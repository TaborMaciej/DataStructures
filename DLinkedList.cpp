#include "DLinkedList.h"


DLinkedList::DLinkedList()
{
	head = NULL;
}

DLinkedList::element DLinkedList::CreateElement()
{
	element object;
	cout << "Creating a new object" << endl;
	cout << "Name: ";
	cin >> object.name;
	cout << "Age: ";
	cin >> object.age;
	cout << endl;
	return object;
}

void DLinkedList::AddStart(element nElement)
{
	element* toAdd = new element;
	*toAdd = nElement;

	if (head != NULL)
	{
		head->prev = toAdd;
		toAdd->next = head;
	}

	head = toAdd;
}

void DLinkedList::AddEnd(element nElement)
{
	element* toAdd = new element;
	*toAdd = nElement;

	if (head != NULL)
	{
		auto temp = head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = toAdd;
		toAdd->prev = temp;
	}
	else
		head = toAdd;
}

DLinkedList::element* DLinkedList::Search(string key)
{
	auto search = head;
	while (search != NULL && search->name != key)
		search = search->next;
	return search;
}

bool DLinkedList::DelFirstName(string key)
{
	auto temp = Search(key);

	if (temp == NULL) return false;

	if (temp == head)
	{
		head->next->prev = NULL;
		head = head->next;
		delete temp;
		return true;
	}
	else if (temp->next == NULL)
	{
		temp->prev->next = NULL;
		delete temp;
		return true;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		return true;
	}
	return false;
}

void DLinkedList::DelAllName(string key)
{
	while (DelFirstName(key));
}

void DLinkedList::Display()
{
	if (head != NULL)
	{
		auto temp = head;
		while (temp != NULL)
		{
			cout << "NAME: " << temp->name << ", AGE: " << temp->age << endl;
			temp = temp->next;
		}
	}
	else
		cout << "List is empty!" << endl;
}