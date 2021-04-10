#pragma once
#include "List.h"

//�������� ��
void List::ShowAll()
{
	Node* current = this->head;

	for (int i = 0; i < GetSize(); i++)
	{
		std::cout << "�����: " << current->word << " | ����� ��������: " << current->pageNumber << std::endl;
		current = current->pNext;
	}
}

//����� ����������� �� �������
void List::ShowByIndex(int index)
{
	if (index < 0 || index > size)
	{
		std::cout << "����� �� �������" << std::endl;
		return;
	}

	Node* current = this->head;
	int counter = 0;

	while (current != nullptr)
	{
		if (counter == index)
		{
			std::cout << "�����: " << current->word << " | ��������: " << current->pageNumber << std::endl;
		}

		counter++;
		current = current->pNext;
	}
}

//����� �������� �� �����
void List::ShowPageNumberByWord(std::string word)
{
	Node* current = this->head;
	bool isExist = false;

	while (current != nullptr)
	{
		if (current->word == word)
		{
			isExist = true;
			std::cout << "�����: " << current->word << " | ����� ��������: " << current->pageNumber << std::endl;
		}

		current = current->pNext;
	}

	if (!isExist)
	{
		std::cout << "������ ����� ���" << std::endl;
	}
}

//����� ����� � ������������ ����������� �������
void List::FindWordWithMaxPageNumber()
{
	Node* current = this->head;

	Node* maxEl = current;
	int max = current->pageNumber;

	while (current != nullptr)
	{
		if (current->pageNumber > max)
		{
			max = current->pageNumber;
			maxEl = current;
		}

		current = current->pNext;
	}

	std::cout << "����� � ������������ ����������� ������� �������: " << maxEl->word << " | ����� ��������: " << max << std::endl;
}

//������� ����� ������
void List::PushWordBefore(std::string checkWord, std::string word, int pageNumber)
{
	if (head == nullptr)
	{
		std::cout << "������ ����� ���" << std::endl;

		return;
	}

	if (head->word == checkWord)
	{
		PushFront(word, pageNumber);

		return;
	}

	
	Node* current = this->head;
	Node* previous = current;

	while (current != nullptr)
	{
		if (checkWord == current->word)
		{
			Node* newNode = new Node(word, pageNumber, previous->pNext);

			previous->pNext = newNode;

			size++;

			return;
		}

		previous = current;
		current = current->pNext;
	}

	std::cout << "������ ����� ���" << std::endl;
}

void List::PushSortedWord(std::string inputWord, List& list)
{
	//� ��������

}

//������� ����� �����
void List::PushWordAfter(std::string checkWord, std::string word, int pageNumber)
{
	Node* current = this->head;
	Node* previous = current;

	int counter = 0;

	while (current != nullptr)
	{
		if (checkWord == current->word)
		{
			if (counter == size - 1)
			{
				PushBack(word, pageNumber);
			}
			else
			{
				Node* newNode = new Node(word, pageNumber, current->pNext);

				current->pNext = newNode;

				size++;
			}

			return;
		}

		counter++;
		previous = current;
		current = current->pNext;
	}

	std::cout << "������ ����� ���" << std::endl;
}

//�������� ����� 
void List::DeleteWord(std::string word)
{
	if (head->word == word)
	{
		Node* temp = this->head;

		head = head->pNext;

		delete temp;

		size--;

		return;
	}

	Node* previous = this->head;
	Node* current = previous;

	while (current != nullptr)
	{
		if (current->word == word)
		{
			if (current->pNext == nullptr)
			{
				delete current;

				previous->pNext = nullptr;

				size--;
			}

			else
			{
				previous->pNext = current->pNext;

				delete current;

				size--;
			}
			return;
		}

		previous = current;
		current = current->pNext;
	}

	std::cout << "������ ����� ���" << std::endl;
}

void List::Clear()
{
	Node* temp = this->head;

	head = head->pNext;

	delete temp;

	size--;
}

//���������� ����� � ������
void List::PushFront(std::string word, int pageNumber)
{
	head = new Node(word, pageNumber, head);

	size++;
}

//���������� ����� � �����
void List::PushBack(std::string word, int pageNumber)
{
	if (head == nullptr)
	{
		head = new Node(word, pageNumber);
	}
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = new Node(word, pageNumber);
	}

	size++;
}

//���������� ��������� []
std::string& List::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->word;
		}
		current = current->pNext;
		counter++;
	}
}