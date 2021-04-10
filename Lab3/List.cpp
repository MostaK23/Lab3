#pragma once
#include "List.h"

//Показать всё
void List::ShowAll()
{
	Node* current = this->head;

	for (int i = 0; i < GetSize(); i++)
	{
		std::cout << "Слово: " << current->word << " | Номер страницы: " << current->pageNumber << std::endl;
		current = current->pNext;
	}
}

//Вывод содержимого по индексу
void List::ShowByIndex(int index)
{
	if (index < 0 || index > size)
	{
		std::cout << "Выход за пределы" << std::endl;
		return;
	}

	Node* current = this->head;
	int counter = 0;

	while (current != nullptr)
	{
		if (counter == index)
		{
			std::cout << "Слово: " << current->word << " | Страница: " << current->pageNumber << std::endl;
		}

		counter++;
		current = current->pNext;
	}
}

//Номер страницы по слову
void List::ShowPageNumberByWord(std::string word)
{
	Node* current = this->head;
	bool isExist = false;

	while (current != nullptr)
	{
		if (current->word == word)
		{
			isExist = true;
			std::cout << "Слово: " << current->word << " | Номер страницы: " << current->pageNumber << std::endl;
		}

		current = current->pNext;
	}

	if (!isExist)
	{
		std::cout << "Такого слова нет" << std::endl;
	}
}

//Поиск слова с максимальным количеством страниц
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

	std::cout << "Слово с максимальным количеством номером страниц: " << maxEl->word << " | Номер страницы: " << max << std::endl;
}

//Вставка перед словом
void List::PushWordBefore(std::string checkWord, std::string word, int pageNumber)
{
	if (head == nullptr)
	{
		std::cout << "Такого слова нет" << std::endl;

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

	std::cout << "Такого слова нет" << std::endl;
}

void List::PushSortedWord(std::string inputWord, List& list)
{
	//В процессе

}

//Вставка после слова
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

	std::cout << "Такого слова нет" << std::endl;
}

//Удаление слова 
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

	std::cout << "Такого слова нет" << std::endl;
}

void List::Clear()
{
	Node* temp = this->head;

	head = head->pNext;

	delete temp;

	size--;
}

//Добавление слова в начало
void List::PushFront(std::string word, int pageNumber)
{
	head = new Node(word, pageNumber, head);

	size++;
}

//Добавление слова в конец
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

//Перегрузка оператора []
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