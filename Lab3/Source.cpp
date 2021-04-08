#include <iostream>
#include <string>
#include <Windows.h>
#include "List.h"
#include "functions.h"


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List list;

	ChooseOperation(list);

	std::cout << "|===================|" << std::endl;
	std::cout << "|====До свидания====|" << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << std::endl;

	return 0;
}