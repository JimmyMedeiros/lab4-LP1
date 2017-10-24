#ifndef _STACK_H
#define _STACK_H 

#include <cstdlib>
#include <memory>

namespace sc {

	template < typename T >
	class stack
	{
		private:
			size_t m_top;
			size_t m_cap;
			std::unique_ptr< T [] > m_storage;

/**
* @brief	Aumenta a capacidade do array alocado.
* @details	Essa função cria um novo array com o tamanho passado e move os elementos para esse array.
* @param	new_cap Um valor do tipo size_t com o tamanho do novo array.
*/
			void reserve( size_t new_cap )
			{
				// if current storage area is large enough, nothing to do here.
				if ( new_cap <= m_cap )
					return;
				// 1) allocate the new storage area.
				std::unique_ptr< T[] > temp(new T[ new_cap ]);
				// 2) Copy/Tranfer/backup elements from the original storage area
				// into the new storage.
				for( auto i(0u) ; i < m_top ; ++i )
					temp[ i ] = m_storage[ i ];
				// 4) Reassign the m_storage storage.
				m_storage = std::move(temp);
				// 5) update the real m_capacity
				m_cap = new_cap;
			}

		public:
			// === Special methods
/**
* @brief	Construtor padrão.
* @param	sz Opcional. Caso seja passado esse valor, como size_t, será alocado um array com tamanho sz.
*/
			explicit stack( size_t sz=1 ) 
			: m_top( 0 ), m_cap( sz ), m_storage( new T[m_cap] ){};
/**
 * @brief Destrutor da classe.
 */
			~stack() = default;
			//=== Interface
			//--- Modifiers
/**
* @brief	Insere um elemento no início da stack.
* @param	value Uma referência constatnte para o elemento do tipo <T>.
*/
			void push( const T& value )
			{
				if( m_top == m_cap )
				{
					reserve(2*m_cap);
				}
				m_storage[m_top++] = value;
			}
/**
* @brief	Remove o elemento no top da stack.
*/
			void pop( void )
			{
				if ( empty() ) throw std::out_of_range( "top() applied to an empty stack.");
				--m_top;
			}
/**
* @brief	Remove todos os elementos (mas não desaloca o array interno).
*/

			void clear( void ) { m_top = 0; }

			//--- Access 
/**
* @brief	Acessa o elemento no topo da stack.
* @return	Retorna um elemento do tipo <T>.
*/
			T top( void ) const
			{
				if ( empty() ) throw std::out_of_range( "top() applied to an empty stack.");

				return m_storage[ m_top-1 ];
			}

			//--- Capcity
/**
* @brief	Verifica se a stack está vazia.
* @return	Retorna true se não houverem elementos na stack, false caso contrário.
*/
			bool empty( void ) const 
			{
				return m_top==0;
			}
/**
* @brief	O tamanho lógico da stack.
* @return	Retorna um size_t com o tamanho da stack.
*/
			size_t size( void ) const 
			{
				return m_top;
			}
	};
}

#endif