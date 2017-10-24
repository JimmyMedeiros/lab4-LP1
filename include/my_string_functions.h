/**
 * @file     my_string_functions.h
 * @brief    Minhas funções criadas para tratamento de std::string.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    24/10/2017
 * @date     24/10/2017
 *
 */
#ifndef _MY_STR_FUNCT_
#define _MY_STR_FUNCT_

#include <string>	// std::string
#include <ctype.h>	// tolower()
#include <locale>         // std::locale, std::ispunct

#include "stack.h"
//#include <stack>

/**
* @brief	Verificar se uma expressão é palíndroma.
* @param	expressao Uma std::string com lower_letter expressão que será verificada.
* @return 	true se lower_letter expressão for palíndroma, false caso contrário.
*/
bool is_palindrome(std::string & expressao)
{
	size_t i;
	sc::stack<char> pilha;

	for (i = 0; i < expressao.size()/2; ++i)
		pilha.push(expressao[i]);

	if (expressao.size()%2)
		i = expressao.size()/2 + 1;
	else
		i = expressao.size()/2;

	for (; i < expressao.size(); ++i)
	{
		if (expressao[i] != pilha.top())
			break;
		pilha.pop();
	}

	if (pilha.empty())
		return true;
	return false;
}
/**
* @brief	Verificar se um char é o primeiro byte de um caracter unicode que possa ser convertido para um caracter ASCII.
* @details	Essa função verifica o byte do char passado e o byte seguinte para verificar se é um caracter unicode.
* OBS: Para entender melhor essa função basta olhar o unicode latim.
* @param	c Um char comum (geralmente 1byte) que faz parte de uma string que pode conter caracteres unicode.
* @param	match Um char do tipo ASCII para verificar se há correspondência com o char c.
* @return 	true se o char for uma das formas acentuadas da letra 'lower_letter', false caso contrário.
*/
bool is_wide_ascii(char& c, char match)
{
	std::string UpperLetter = "\303\200";
	std::string lower_letter = "\303\240";
	size_t lim; // a quantidade de letras em sequencia na tabela unicode

	switch(match){
		case 'a':
			UpperLetter = "\303\200";
			lower_letter = "\303\240";
			lim = 6;
			break;
		case 'e':
			UpperLetter = "\303\210";
			lower_letter = "\303\250";
			lim = 4;
			break;
		case 'i':
			UpperLetter = "\303\214";
			lower_letter = "\303\254";
			lim = 4;
			break;
		case 'o':
			UpperLetter = "\303\222";
			lower_letter = "\303\262";
			lim = 5;
			break;
		case 'u':
			UpperLetter = "\303\231";
			lower_letter = "\303\271";
			lim = 4;
			break;
		case 'c':
			UpperLetter = "\303\207";
			lower_letter = "\303\247";
			lim = 1;
			break;
		default:
			return false;
	}
	
	if (c == UpperLetter[0] or c == lower_letter[0])
	{
		for (size_t i = 0; i < lim; ++i)
		{
			if ((*(&c+1) == (UpperLetter[1])) or (*(&c+1) == (lower_letter[1])))
			{
				return true;
			}
			++UpperLetter[1];
			++lower_letter[1];
		}
	}
	return false;
}

#endif