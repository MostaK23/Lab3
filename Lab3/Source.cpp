#include <iostream>
#include <string>
#include <Windows.h>
#include "List.h"
#include "functions.h"
#include <algorithm>

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List list;

	list.PushBack("Коза", 60);
	list.PushBack("Курица", 8);
	list.PushBack("Корова", 150);
	
	std::cout << "До: " << std::endl;
	list.ShowAll();

	list.PushSortedWord("A");
	

	std::cout << "После: " << std::endl;
	list.ShowAll();


	//ChooseOperation(list);


	std::cout << "|===================|" << std::endl;
	std::cout << "|====До свидания====|" << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << std::endl;

	return 0;
}