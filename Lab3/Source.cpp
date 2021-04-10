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

	list.PushBack("����", 60);
	list.PushBack("������", 8);
	list.PushBack("������", 150);
	
	std::cout << "��: " << std::endl;
	list.ShowAll();

	list.PushSortedWord("A");
	

	std::cout << "�����: " << std::endl;
	list.ShowAll();


	//ChooseOperation(list);


	std::cout << "|===================|" << std::endl;
	std::cout << "|====�� ��������====|" << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << std::endl;

	return 0;
}