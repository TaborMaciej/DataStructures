#pragma once
#include <iostream>
using namespace std;
class Queue
{
private:
	struct element
	{
		string name;
		int age;
		element* next;
	};

	element* front;
	element* rear;
public:

	Queue();
	static element CreateElement();
	void EnQueue(element nElement);
	bool DeQueue();
	void DelAll();
	void Display();

};

