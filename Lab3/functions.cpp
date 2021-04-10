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

//����� ��������
void ChooseOperation(List& list)
{
	bool inProcess = true;
	int choise;

	CreateList(list);

	while (inProcess)
	{
		OperationList();

		std::cout << "��� �����: ";
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
			std::cout << "������� ������������ �����" << std::endl;
			Delay();
			break;
		}
	}
}

//���� ��������
void OperationList()
{
	std::cout << "|1|����� ������" << std::endl;
	std::cout << "|2|����� ������� ������� ��� ��������� �����" << std::endl;
	std::cout << "|3|����� ����� � ������������ ����������� ������� �������" << std::endl;
	std::cout << "|4|���������� ������ ����� � ������ ������" << std::endl;
	std::cout << "|5|���������� ������ ����� � ����� ������" << std::endl;
	std::cout << "|6|--------------------� ��������" << std::endl;
	std::cout << "|7|���������� ������ ����� ����� ��������� ������" << std::endl;
	std::cout << "|8|���������� ������ ����� ����� ���������� �����" << std::endl;
	std::cout << "|9|�������� ���������� �����" << std::endl;
	std::cout << "|0|�����" << std::endl;
}

//������� ������
void CreateList(List& list)
{
	std::cout << "|===========================|" << std::endl;
	std::cout << "|������� ������������ ������|" << std::endl;
	std::cout << "|===========================|" << std::endl;
	std::cout << std::endl;

	int count;
	std::cout << "������� ��������� ������ ��������: ";
	std::cin >> count;
	std::cout << "|===========================|" << std::endl;

	std::string word;
	int pageNumber;

	for (int i = 0; i < count; i++)
	{
		std::cout << "������� �����: ";
		std::cin >> word;

		ToCapitalLetter(word);

		std::cout << "������� ����� ��������: ";
		std::cin >> pageNumber;

		list.PushBack(word, pageNumber);
		std::cout << "|===========================|" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "|===========================|" << std::endl;
	std::cout << "|=========���������=========|" << std::endl;
	std::cout << "|===========================|" << std::endl;

	Delay();
}

//������� ������
void ShowList(List& list) 
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|��� ����������|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	list.ShowAll();

	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;

	Delay();
}

//������� ����� �������� �� ��������� �����
void ShowNumberByWord(List& list)
{
	system("cls");

	std::cout << "|=======================|" << std::endl;
	std::cout << "|����� �������� �� �����|" << std::endl;
	std::cout << "|=======================|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "������� ����� ��� ������: ";
	std::cin >> word;

	ToCapitalLetter(word);

	list.ShowPageNumberByWord(word);

	std::cout << std::endl;
	std::cout << "|=======================|" << std::endl;
	Delay();
}

//����� ������������ ��������
void FindMaxPage(List& list)
{
	system("cls");

	std::cout << "|===========================|" << std::endl;
	std::cout << "|����� ������������ ��������|" << std::endl;
	std::cout << "|===========================|" << std::endl;
	std::cout << std::endl;

	list.FindWordWithMaxPageNumber();

	std::cout << std::endl;
	std::cout << "|===========================|" << std::endl;

	Delay();
}

//�������� � ������
void PushFront(List& list)
{
	system("cls");

	std::cout << "|===================|" << std::endl;
	std::cout << "|���������� � ������|" << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << std::endl;


	std::string word;
	std::cout << "������� �����: ";
	std::cin >> word;

	ToCapitalLetter(word);

	int pageNumber;
	std::cout << "������� ����� ��������: ";
	std::cin >> pageNumber;

	list.PushFront(word, pageNumber);

	std::cout << std::endl;
	std::cout << "|===================|" << std::endl;
	std::cout << "|=====���������=====|" << std::endl;
	std::cout << "|===================|" << std::endl;
	
	Delay();
}

//�������� � �����
void PushBack(List& list)
{
	system("cls");

	std::cout << "|==================|" << std::endl;
	std::cout << "|���������� � �����|" << std::endl;
	std::cout << "|==================|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "������� �����: ";
	std::cin >> word;

	ToCapitalLetter(word);

	int pageNumber;
	std::cout << "������� ����� ��������: ";
	std::cin >> pageNumber;
	
	list.PushBack(word, pageNumber);

	std::cout << std::endl;
	std::cout << "|==================|" << std::endl;
	std::cout << "|=====���������====|" << std::endl;
	std::cout << "|==================|" << std::endl;

	Delay();
}

//�������� ��������������� �����
void PushSort(List& list)
{
	system("cls");

	std::cout << "|=============|" << std::endl;
	std::cout << "|� ��������...|" << std::endl;
	std::cout << "|=============|" << std::endl;
	std::cout << std::endl;

	Delay();
}

//�������� ����� ���������� ������
void PushBefore(List& list)
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|�������� �����|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "������� �����, ����� ������� ���� ��������: ";
	std::cin >> word;

	ToCapitalLetter(word);

	std::string inputWord;
	std::cout << "������� ����� ��� �������: ";
	std::cin >> inputWord;

	ToCapitalLetter(inputWord);

	int pageNumber;
	std::cout << "������� ����� ��������: ";
	std::cin >> pageNumber;
 
	list.PushWordBefore(word, inputWord, pageNumber);

	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << "|   ���������  |" << std::endl;
	std::cout << "|==============|" << std::endl;

	Delay();
}

//�������� ����� ����������� �����
void PushAfter(List& list)
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|�������� �����|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "������� �����, ����� �������� ���� ��������: ";
	std::cin >> word;

	ToCapitalLetter(word);

	std::string inputWord;
	std::cout << "������� ����� ��� �������: ";
	std::cin >> inputWord;

	ToCapitalLetter(inputWord);

	int pageNumber;
	std::cout << "������� ����� ��������: ";
	std::cin >> pageNumber;


	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << "|   ���������  |" << std::endl;
	std::cout << "|==============|" << std::endl;


	Delay();
}

//�������� �����
void DeleteWord(List& list)
{
	system("cls");

	std::cout << "|==============|" << std::endl;
	std::cout << "|�������� �����|" << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << std::endl;

	std::string word;
	std::cout << "������� ����� ��� ��������: ";
	std::cin >> word;

	ToCapitalLetter(word);

	list.DeleteWord(word);

	std::cout << std::endl;
	std::cout << "|==============|" << std::endl;
	std::cout << "|===���������==|" << std::endl;
	std::cout << "|==============|" << std::endl;


	Delay();
}