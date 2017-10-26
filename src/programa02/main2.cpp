/**
 * @file     main2.cpp
 * @brief    Programa02: Uma programa que recebe uma expresão em notação polonesa inversa calcula o resultado e transforma para infixa.
 *
 * @author   Josivan Medeiros da Silva Gois
 * @since    26/10/2017
 * @date     26/10/2017
 *
 */

#include <string>
#include <iostream>

#include "bares.h"

int main(int argc, char const *argv[])
{
	std::string expressao_RPN;

	std::cout << "Digite a expressão RPN: \n";
	getline( std::cin, expressao_RPN );

	auto result = evaluate_postfix(expressao_RPN);

	std::cout << "O resultado é: " << result << std::endl;

	return 0;
}