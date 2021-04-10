#pragma once
#include "functions.h"
#include <string>
#include <cstring>

void ToCapitalLetter(std::string& str)
{
	if (str.empty())
		return;

	for (int i = 0; i < str.length(); i++)
	{
		if (i > 0)
		{
			str[i] = std::tolower(str[i]);
		}
		if (i == 0)
		{
			str[i] = std::toupper(str[i]);
		}
	}
}

void Delay()
{
	system("pause");
	system("cls");
}

//Выбор операции
void ChooseOperation(List& list)
{
	bool inProcess = true;
	int choise;

	CreateList(list);

	while (inProcess)
	{
		OperationList();

		std::cout << "Ваш выбор: ";
		std::cin >> choise;

		switch (choise)
		{
		case 1:
			ShowList(list);
			break;
		case 2:
			ShowNumberByWord(list);
			break;
		case 3:
			FindMaxPage(list);
			break;
		case 4:
			PushFront(list);
			break;
		case 5:
			PushBack(list);
			break;
		case 6:
			PushSort(list);
			break;
		case 7:
			PushBefore(list);
			break;
		case 8:
			PushAfter(list);
			break;
		case 9:
			DeleteWord(list);
			break;
		case 0:
			inProcess = false;
			break;
		default:
			std::cout << "Укажите существующий пункт" << std::endl;
			Delay();
			break;
		}
	}
}

//Лист операций
void OperationList()
{
	std::cout << "|1|Вывод списка" << std::endl;
	std::cout << "|2|Вывод номеров страниц для заданного слова" << std::endl;
	std::cout << "|3|Поиск слова с максимальным количеством номером страниц" << std::endl;
	std::cout << "|4|Добавление нового слова в начало списка" << std::endl;
	std::cout << "|5|Добавление нового слова в конец списка" << std::endl;
	std::cout << "|6|--------------------В процессе" << std::endl;
	std::cout << "|7|Добавление нового слова перед указанным словом" << std::endl;
	std::cout << "|8|Добавление нового слова после указанного слова" << std::endl;
	std::cout << "|9|Удаление указанного слова" << std::endl;
	std::cout << "|0|Выход" << std::endl;
}

//Создать список
void CreateList(List& list)
{
	std::cout << "|===========================|" << std::endl;
	std::cout << "|Сначала сформируемый список|" << std::endl;
	std::cout << "|===========================|" << std::endl;
	std::cout << std::endl;

	int count;
	std::cout << "Сколько элементов хотите добавить: ";
	std::cin >> count;
	std::cout << "|===========================|" << std::endl;

	std::string word;
	int pageNumber;

	for (int i = 0; i < count; i++)
	{
		std::cout << "Введите слово: ";
		std::cin >> word;

		ToCapitalLetter(word);

		std::cout << "Введите номер страницы: ";
		std::cin >> pageNumber;

		list.PushBack(word, pageNumber);
		std::cout << "|===========================|" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "|===========================|" << std::endl;
	std::cout << "|=========Выполнено=========|" << std::endl;
	std::cout << "|===========================|" << std::endl;

	Delay();
}

//Вывести список
void ShowList(List& list) 
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|Вся информация|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	list.ShowAll();

	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;

	Delay();
}

//Вывести номер страницы по заданному слову
void ShowNumberByWord(List& list)
{
	system("cls");

	std::cout << "|=======================|" << std::endl;
	std::cout << "|Поиск страницы по слову|" << std::endl;
	std::cout << "|=======================|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "Введите слово для поиска: ";
	std::cin >> word;

	ToCapitalLetter(word);

	list.ShowPageNumberByWord(word);

	std::cout << std::endl;
	std::cout << "|=======================|" << std::endl;
	Delay();
}

//Найти максимальную страницу
void FindMaxPage(List& list)
{
	system("cls");

	std::cout << "|===========================|" << std::endl;
	std::cout << "|Поиск максимальной страницы|" << std::endl;
	std::cout << "|===========================|" << std::endl;
	std::cout << std::endl;

	list.FindWordWithMaxPageNumber();

	std::cout << std::endl;
	std::cout << "|===========================|" << std::endl;

	Delay();
}

//Вставить в начало
void PushFront(List& list)
{
	system("cls");

	std::cout << "|===================|" << std::endl;
	std::cout << "|Добавление в начало|" << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << std::endl;


	std::string word;
	std::cout << "Введите слово: ";
	std::cin >> word;

	ToCapitalLetter(word);

	int pageNumber;
	std::cout << "Введите номер страницы: ";
	std::cin >> pageNumber;

	list.PushFront(word, pageNumber);

	std::cout << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << "|=====Выполнено=====|" << std::endl;
	std::cout << "|===================|" << std::endl;
	
	Delay();
}

//Вставить в конец
void PushBack(List& list)
{
	system("cls");

	std::cout << "|==================|" << std::endl;
	std::cout << "|Добавление в конец|" << std::endl;
	std::cout << "|==================|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "Введите слово: ";
	std::cin >> word;

	ToCapitalLetter(word);

	int pageNumber;
	std::cout << "Введите номер страницы: ";
	std::cin >> pageNumber;
	
	list.PushBack(word, pageNumber);

	std::cout << std::endl;
	std::cout << "|==================|" << std::endl;
	std::cout << "|=====Выполнено====|" << std::endl;
	std::cout << "|==================|" << std::endl;

	Delay();
}

//Вставить отсортировонное слова
void PushSort(List& list)
{
	system("cls");

	std::cout << "|=============|" << std::endl;
	std::cout << "|В процессе...|" << std::endl;
	std::cout << "|=============|" << std::endl;
	std::cout << std::endl;

	Delay();
}

//Вставить перед конкретным словом
void PushBefore(List& list)
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|Добавить перед|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "Введите слово, перед которым надо вставить: ";
	std::cin >> word;

	ToCapitalLetter(word);

	std::string inputWord;
	std::cout << "Введите слово для вставки: ";
	std::cin >> inputWord;

	ToCapitalLetter(inputWord);

	int pageNumber;
	std::cout << "Введите номер страницы: ";
	std::cin >> pageNumber;
 
	list.PushWordBefore(word, inputWord, pageNumber);

	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << "|   Выполнено  |" << std::endl;
	std::cout << "|==============|" << std::endl;

	Delay();
}

//Вставить после конкретного слова
void PushAfter(List& list)
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|Добавить после|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "Введите слово, после которого надо вставить: ";
	std::cin >> word;

	ToCapitalLetter(word);

	std::string inputWord;
	std::cout << "Введите слово для вставки: ";
	std::cin >> inputWord;

	ToCapitalLetter(inputWord);

	int pageNumber;
	std::cout << "Введите номер страницы: ";
	std::cin >> pageNumber;


	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << "|   Выполнено  |" << std::endl;
	std::cout << "|==============|" << std::endl;


	Delay();
}

//Удаление слова
void DeleteWord(List& list)
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|Удаление слова|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "Введите слово для удаления: ";
	std::cin >> word;

	ToCapitalLetter(word);

	list.DeleteWord(word);

	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << "|===Выполнено==|" << std::endl;
	std::cout << "|==============|" << std::endl;


	Delay();
}