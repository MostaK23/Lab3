#pragma once

#include <iostream>
#include <string>

class List
{
public:
	List()
	{
		size = 0;
		head = nullptr;
	}

	~List()
	{
		Clear();
	}

	void PushBack(std::string, int);
	void PushFront(std::string, int);
	int GetSize() { return size; }
	void ShowAll();
	void ShowByIndex(int);
	void ShowPageNumberByWord(std::string);
	void FindWordWithMaxPageNumber();
	void PushSortedWord(std::string, List&);
	void PushWordBefore(std::string, std::string, int);
	void PushWordAfter(std::string, std::string, int);
	void DeleteWord(std::string);
	
	
	std::string& operator[](const int index);

private:

	void Clear();

	class Node
	{
	public:
		std::string word;
		int pageNumber;
		Node* pNext;

		Node(std::string word = "", int pageNumber = 0, Node* pNext = nullptr)
		{
			this->word = word;
			this->pageNumber = pageNumber;
			this->pNext = pNext;
		}
	};

	Node* head;
	int size;
};