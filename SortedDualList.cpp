#include "SortedDualList.h"


SortedDualList::SortedDualList()
{
	head = NULL;
}

SortedDualList::element SortedDualList::CreateElement()
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

void SortedDualList::Add()
{
	auto toAdd = new element;
	*toAdd = CreateElement();
	if (head == NULL)
	{
		head = toAdd;
		return;
	}

	auto temp = head;
	while (temp->next != NULL && temp->name < toAdd->name)	temp = temp->next;


	if (temp->next == NULL && temp->name < toAdd->name) //end of the list
	{
		temp->next = toAdd;
		toAdd->prev = temp;
		return;
	}

	if (temp->prev == NULL && temp->name > toAdd->name) //begining of the list
	{
		temp->prev = toAdd;
		toAdd->next = temp;
		head = toAdd;
		return;
	}

	if (temp->name > toAdd->name)
	{
		toAdd->next = temp;
		toAdd->prev = temp->prev;
		temp->prev->next = toAdd;
		temp->prev = toAdd;
		return;
	}

	if (temp->name < toAdd->name)
	{
		toAdd->prev = temp;
		toAdd->next = temp->next;
		temp->next->prev = toAdd;
		temp->next = toAdd;
		return;
	}
	

}

void SortedDualList::Display()
{
	if (head == NULL)
	{
		cout << "List is empty!" << endl;
		return;
	}

	auto temp = head;
	while (temp != NULL)
	{
		cout << "NAME: " << temp->name << ", AGE: " << temp->age << endl;
		temp = temp->next;
	}
}

SortedDualList::element* SortedDualList::Search(string key)
{
	auto search = head;

	while (search != NULL)
		if (search->name == key) return search;

	return NULL;
}

bool SortedDualList::DelFirstName(string key)
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

void SortedDualList::DelAllName(string key)
{
	while (DelFirstName(key));
}