#include "Stack.h"

Stack::Stack()
{
	head = NULL;
}

Stack::element Stack::CreateElement()
{
	element object;
	cout << "Creating a new object" << endl;
	cout << "Name: ";
	cin >> object.name;
	cout << "Age: ";
	cin >> object.age;
	cout << endl;
	object.prev = NULL;

	return object;
}
void Stack::Push(element nElement)
{
	element* temp = head;
	element* toAdd = new element;

	*toAdd = nElement;
	head = toAdd;
	toAdd->prev = temp;

}

bool Stack::Pop()
{
	if (head != NULL)
	{
		element* temp = head;
		head = head->prev;
		delete temp;
		return true;
	}
	else
		return false;
}

void Stack::Display()
{
	auto copy = head;
	while (copy != NULL)
	{
		cout << "Name: " << copy->name << ", age: " << copy->age << endl;
		copy = copy->prev;
	}
}

void Stack::Delete()
{
	while (Pop());
	head = NULL;
}