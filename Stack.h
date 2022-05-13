#pragma once
#include <iostream>
using namespace std;
class Stack
{
private:
	struct element
	{
		string name;
		int age;
		element* prev;
	};

	element* head;

public: 
	Stack();

	static element CreateElement();
	void Push(element nElement);
	bool Pop(); //true if element was deleted ; false if not
	void Display();
	void Delete();
};

