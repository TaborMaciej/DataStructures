#pragma once
#include <iostream>
using namespace std;

class SortedDualList
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
	element CreateElement();

public:
	SortedDualList();

	void Add(); //Adds an element
	void Display(); //Displays contents of the list

	element* Search(string key); //Returns a pointer to an element which name matches the key name
	bool DelFirstName(string key); //Deletes first element which name matches the key name
	void DelAllName(string key); //Deletes all elements which names match the key name

};