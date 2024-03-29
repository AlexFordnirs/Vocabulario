//
// На GitHub немогу авторизоватся...
//
#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
class vocabulario
{
public:
	vocabulario();

	void push_back(T engWord, T frnWord);

	void operator[](const int index);

	void pop_front();

	void clear();

	void push_front(T engWord, T frnWord);

	void insert(T engWord, T frnWord, int index);

	int getSize() { return size; }

	void removeAt(int index);

	~vocabulario();
private:
	template<typename T>
	class node
	{
	public:
		node *pNext;
		T engWord;
		T frnWord;
		node(T engWord = T(), T frnWord = T(), node *pNext = nullptr)
		{
			this->engWord = engWord;
			this->frnWord = frnWord;
			this->pNext = pNext;
		}
	};

	int size;
	node<T> *head;
};

int main()
{
	setlocale(LC_ALL, "rus");

	vocabulario<char*> word;

	while (true)
	{
		system("cls");
		cout << "Выберите действие:\n0 - Вывести слова\n1 - Добавить перевод\n2 - Добавить перевод в начало\n3 - Удалиь перевод\n4 - Удалиь все данные\n5 - Редактировать данные\n6 - Выйти из программы" << endl;
		int choice;
		cout << "Ваше действие: ";
		cin >> choice;
		switch (choice)
		{
			case 0:
			{
				system("cls");
				for (int i = 0; i < word.getSize(); i++)
				{
					cout << i << ")";
					word[i];
				}
				system("pause");
				break;
			}
			case 1:
			{
				system("cls");
				char *engWord = new char[64];
				char *frnWord = new char[64];
				cout << "Введите слово на английском языке: ";
				cin >> (char*)engWord;
				cout << "Введите перевод слова на фрнцузком: ";
				cin >> (char*)frnWord;
				word.push_back(engWord, frnWord);
				break;
			}
			case 2:
			{
				system("cls");
				char *engWord = new char[64];
				char *frnWord = new char[64];
				cout << "Введите слово на английском языке: ";
				cin >> (char*)engWord;
				cout << "Введите перевод слова на фрнцузком: ";
				cin >> (char*)frnWord;
				word.push_front(engWord, frnWord);
				break;
			}
			case 3:
			{
				system("cls");
				for (int i = 0; i < word.getSize(); i++)
				{
					cout << i << ")";
					word[i];
				}
				cout << "Выберите елемент, кторый хотите удалить: ";
				int index = 0;
				cin >> index;
				if(index >= 0 && index < word.getSize())
				{ 
					word.removeAt(index);
					cout << "Вы удалили перевод..." << endl;
				}
				else
				{
					cout << "Перевода с таким индексом нету..." << endl;
					system("pause");
				}
				break;
			}
			case 4:
			{
				system("cls");
				for (int i = 0; i < word.getSize(); i++)
				{
					cout << i << ")";
					word[i];
				}
				cout << "Вы точно хотите удалить все данные из словника? 0 - нет : 1 - да: ";
				int del;
				cin >> del;
				if (del == 1)
				{
					word.clear();
					cout << "Все данные были удалены..." << endl;
					system("pause");
				}
				else if (del == 0)
				{
					cout << "Отменено..." << endl;
					system("pause");
				}
				else
				{
					cout << "Неверное значение..." << endl;
					system("pause");
				}
				break;
			}
			case 5:
			{
				system("cls");
				for (int i = 0; i < word.getSize(); i++)
				{
					cout << i << ")";
					word[i];
				}
				cout << "Какой елемент хотите изменить? ";
				int index = 0;
				cin >> index;
				if(index >= 0 && index < word.getSize())
				{ 
					word.removeAt(index);
					char *engWord = new char[64];
					char *frnWord = new char[64];
					cout << "Введите слово на английском языке: ";
					cin >> (char*)engWord;
					cout << "Введите перевод слова на фрнцузком: ";
					cin >> (char*)frnWord;
					word.insert(engWord, frnWord, index);
					for (int i = 0; i < word.getSize(); i++)
					{
						cout << i << ")";
						word[i];
					}
					system("pause");
				}
				else
				{
					cout << "Таких данных не существует..." << endl;
					system("pause");
				}
				break;
			}
			case 6:
			{
				exit(0);
				break;
			}
		default:
			cout << "Неверное значение..." << endl;
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}

template<typename T>
vocabulario<T>::vocabulario()
{
	size = 0;
	head = nullptr;
}

template<typename T>
void vocabulario<T>::push_back(T engWord, T frnWord)
{
	if (head == nullptr)
	{
		head = new node<T>(engWord, frnWord);
	}
	else
	{
		node<T> *current = head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new node<T>(engWord, frnWord);
	}

	size++;
}

template<typename T>
void vocabulario<T>::operator[](const int index)
{
	int counter = 0;
	node<T> *current = head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			cout << current->engWord << " - " << current->frnWord << endl;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void vocabulario<T>::pop_front()
{
	node<T> *temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename T>
void vocabulario<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void vocabulario<T>::push_front(T engWord, T frnWord)
{
	head = new node<T>(engWord, frnWord, head);
	size++;
}

template<typename T>
void vocabulario<T>::insert(T engWord, T frnWord, int index)
{
	if (index == 0)
	{
		push_front(engWord, frnWord);
	}
	else
	{
		node<T> *temp = head;

		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}

		node<T> *newNode = new node<T>(engWord, frnWord, temp->pNext);
		temp->pNext = newNode;
		size++;
	}
}

template<typename T>
void vocabulario<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		node<T> *temp = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}

		node<T> *toDelete = temp->pNext;

		temp->pNext = toDelete->pNext;

		delete toDelete;

		size--;
	}
}

template<typename T>
vocabulario<T>::~vocabulario()
{
	clear();
}
