/*
 * @file	lista_ordenada.h
 * @brief	Declaração e implementação da classe ListaOrdenada, subclasse da ListaDuplamenteLigada
 *
 * @author	Josivan Medeiros da Silva Gois
 * @since	28/10/2017
 * @date	28/10/2017
 */

#ifndef _LISTA_ORDENADA_
#define _LISTA_ORDENADA_ 

#include "lista.h"

template <class T> 
class ListaOrdenada : public ListaDuplamenteLigada<T>
{
public:
	ListaOrdenada() : ListaDuplamenteLigada<T>() {};
	~ListaOrdenada()
	{
		std::cout << "destruindo lista_ordenada" << std::endl;
		this->~ListaDuplamenteLigada<T>();
	}

	bool Insere(T _valor)
	{
		if (this->tamanho == 0 or _valor < this->cabeca->getValor())
			return this->InsereNoInicio(_valor);
		else if (_valor > this->cauda->getValor())
			return this->InsereNoFinal(_valor);
		
		auto atual = this->cauda;

		while (_valor < atual->getPrevious()->getValor())
			atual = atual->getPrevious();
		atual = atual->getPrevious();

		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		novo->setNext(atual->getNext());
		novo->setPrevious(atual);
		atual->setNext(novo);
		this->tamanho++;

		return true;
	}
};

#endif