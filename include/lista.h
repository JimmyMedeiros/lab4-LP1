#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include <memory>

using namespace std;

/* Implementacao da classe Node */

// Para permitir sobrecarregar o operador de insercao
// numa classe template como friend eh preciso adicionar
// o trecho de codigo a seguir
template <typename T> class Node; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Node<T> const & );
// --

template <class T>
class Node
{
private:
	T valor;
	shared_ptr<Node<T>> proximo;
	shared_ptr<Node<T>> anterior;
public:
	Node()
		: valor(), proximo(nullptr), anterior(nullptr) {};
	
	Node(T _valor)
		: valor(_valor), proximo(nullptr), anterior(nullptr) {};
	
	Node(T _valor, shared_ptr<Node> nextPtr)
		: valor(_valor), proximo(nextPtr), anterior(nullptr) {};
	
	/*Node(T _valor, shared_ptr<Node> nextPtr, shared_ptr<Node> previousPtr)
		: valor(_valor), proximo(nextPtr), anterior(previousPtr) {};*/

	~Node()
	{
		cout << "Node(" << valor << ") removido." << endl;
	}
	T getValor()
	{
		return valor;
	}
	shared_ptr<Node<T>> getNext()
	{
		return proximo;
	}
	shared_ptr<Node<T>> getPrevious()
	{
		return anterior;
	}
	void setNext(shared_ptr<Node<T>> nextPtr)
	{
		proximo = nextPtr;
	}
	void setPrevious(shared_ptr<Node<T>> previousPtr)
	{
		anterior = previousPtr;
	}

	friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
};
template <typename T>
std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
	o << n.valor;
	return o;
}
/* Implementacao da classe ListaDuplamenteLigada */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend eh preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class ListaDuplamenteLigada; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaDuplamenteLigada<T> const & );
// --

template <typename T>
class ListaDuplamenteLigada {
protected:
	shared_ptr<Node<T>> cabeca;
	shared_ptr<Node<T>> cauda;
	int tamanho;
public:
	ListaDuplamenteLigada() : cabeca( nullptr ), cauda( nullptr ), tamanho( 0 ) {};
	~ListaDuplamenteLigada()
	{
		std::cout << "Destruindo lista ligada\n";
		while (this->cabeca != this->cauda)
		{
			cabeca->setPrevious(nullptr);
			cabeca = cabeca->getNext();
			cabeca->getPrevious()->setNext(nullptr);
		}
	}
	bool InsereNoInicio(T _valor)
	{
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		novo->setNext(this->cabeca);
		this->cabeca = novo;
		this->tamanho++;
		if (this->cauda == nullptr)
		{
			this->cauda = novo;
			this->cauda->setNext(nullptr);
		}
		else
			this->cabeca->getNext()->setPrevious(this->cabeca);
		return true;
	}
	bool InsereNoFinal(T _valor)
	{
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		novo->setPrevious(this->cauda);
		this->cauda = novo;
		this->tamanho++;
		if (this->cabeca == nullptr)
			this->cabeca = novo;
		else
			this->cauda->getPrevious()->setNext(this->cauda);
		return true;
	}
	bool InsereNaPosicao(int pos, T _valor)
	{
		if (pos<0)	return false;
		if (pos==0)	return InsereNoInicio(_valor);
		if (pos==((this->tamanho)-1))	return InsereNoFinal(_valor);

		auto atual = this->cabeca;
		int posAtual = 0;
		while (atual->getNext() != this->cauda && posAtual < pos-1) {
			atual = atual->getNext();
			posAtual++;
		}
		
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		novo->setNext(atual->getNext());
		novo->setPrevious(atual);
		atual->setNext(novo);
		this->tamanho++;
		
		return true;
	}
	bool RemoveNoInicio()
	{
		if (this->cabeca==nullptr) return false;
		cabeca->getNext()->setPrevious(nullptr);
		cabeca = cabeca->getNext();
		this->tamanho--;
		return true;
	}
	bool RemoveNoFinal()
	{
		if (this->cauda==nullptr) return false;
		cauda->getPrevious()->setNext(nullptr);
		cauda = cauda->getPrevious();
		this->tamanho--;
		return true;
	}
	bool RemoveNaPosicao(int pos)
	{
		if (pos<0) return false;
		if (pos==0)	return RemoveNoInicio();
		if (pos==((this->tamanho)-1))	return RemoveNoFinal();

		auto atual = this->cabeca;
		int posAtual = 0;
		while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
			atual = atual->getNext();
			posAtual++;
		}

		atual->setNext(atual->getNext()->getNext());
		this->tamanho--;

		return true;
	}

	int size()
	{
		return this->tamanho;
	}

	friend std::ostream& operator<< <T>( std::ostream&, ListaDuplamenteLigada<T> const &l);
};

template <typename T>
std::ostream& operator<< ( std::ostream& o, ListaDuplamenteLigada<T> const &l) {
	auto atual = l.cabeca;
	while (atual != nullptr) {
		o << atual->getValor() << " ";
		atual = atual->getNext();
	}
	return o;
}

#endif