#pragma once
#include <iostream>
using namespace std;

class DLinkedList
{
private:
	struct element
	{
		string name;
		int age;
		element* next = NULL;
		element* prev = NULL;
	};

	element* head;

public:
	DLinkedList();

	static element CreateElement();
	void AddStart(element nElement); //Adds an element at the start
	void AddEnd(element nElement); //Adds an element at the end
	void Display();

	element* Search(string key); //Returns a pointer to an element which name matches the key name
	bool DelFirstName(string key); //Deletes first element which name matches the key name
	void DelAllName(string key); //Deletes all elements which names match the key name

};

