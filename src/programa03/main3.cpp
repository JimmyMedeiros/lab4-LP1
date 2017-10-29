#include <iostream>
//#include "pilha.h"
#include "lista.h"
#include "lista_ordenada.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

	/*Pilha<int> pilha;
	cout << "Tamanho: " << pilha.size() << endl;
	pilha.push(10);
	pilha.push(15);
	pilha.push(20);
	cout << pilha.top() << endl;
	pilha.pop();
	cout << "Tamanho: " << pilha.size() << endl;
	cout << pilha.top() << endl;
	pilha.pop();
	cout << pilha.top() << endl;
	pilha.pop();*/

	cout << "Testando a lista..." << endl;

	ListaDuplamenteLigada<int> lista1;
	cout << "Tamanho: " << lista1.size() << endl;
	lista1.InsereNoInicio(2);
	lista1.InsereNoInicio(3);
	lista1.InsereNoInicio(4);
	
	lista1.InsereNoFinal(3);
	lista1.InsereNoFinal(4);
	lista1.InsereNaPosicao(0,1);
	lista1.InsereNoFinal(6);
	lista1.InsereNaPosicao(4,5);
	lista1.InsereNoFinal(7);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNaPosicao(3);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoInicio();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoFinal();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;


	cout << "Testando a lista ordenada..." << endl;

	ListaOrdenada<int> lista2;
	cout << "Tamanho: " << lista2.size() << endl;
	lista2.Insere(1);
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.Insere(2);
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.Insere(3);
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.Insere(4);
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.Insere(0);
	lista2.Insere(3);
	//lista2.InsereNoFinal(4);
	//lista2.InsereNaPosicao(0,1);
	//lista2.InsereNoFinal(6);
	//lista2.InsereNaPosicao(4,5);
	//lista2.InsereNoFinal(7);
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.RemoveNaPosicao(3);
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.RemoveNoInicio();
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << endl;
	lista2.RemoveNoFinal();
	cout << "Tamanho: " << lista2.size() << endl;
	cout << lista2 << "		Acabou" << endl;
	return 0;
}