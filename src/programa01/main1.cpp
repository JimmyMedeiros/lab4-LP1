/**
 * @file     main1.cpp
 * @brief    Programa01: um código para avaliar se uma expressão é palíndroma utilizando a estrutura de Pilha (Stack).
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    22/10/2017
 * @date     24/10/2017
 *
 * @mainpage Laboratório 4 de LP1
 *
 * @section intro_sec Introdução
 *
 * Esse laboratório é uma implementação de 3 programas. @TODO
 *
 */
#include <iostream>	// std::cout, std::cin
#include <string>	// std::string
#include <ctype.h>	// tolower()
#include <locale>         // std::locale, std::ispunct

#include "stack.h"
#include "my_string_functions.h"

int main(int argc, char const *argv[])
{
	std::string expressao;
	sc::stack<char> pilha;

	std::cout << "Digite uma palavra ou expressão para ser avaliada" << std::endl;
	std::getline(std::cin, expressao);
	
	// Removendo acentos
	std::string aux;
	for (size_t i = 0; i < expressao.size(); ++i)
	{
		auto temp = (char) tolower((int) expressao[i]); 
		if (isalnum(expressao[i]))
		{
			aux.append(&(temp), 1);
		}
		else
		{
			std::string letras = "aeiouc";
			for (char v : letras)
			{
				if (is_wide_ascii(expressao[i], v)){
					aux.append(&v, 1);
					break;
				}
			}
		}
	}
	//expressao = aux;

	//std::cout << "String tratada:" << expressao << "\n";

	std::cout << std::endl;
	if (is_palindrome(aux))
	{
		std::cout << "A expressão \"" << expressao << "\" é Palídroma" << std::endl;
	}
	else
	{
		std::cout << "A expressão \"" << expressao << "\" não é Palídromo" << std::endl;
	}
	
	return 0;
}