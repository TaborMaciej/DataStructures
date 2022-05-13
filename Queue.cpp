#include "Queue.h"

Queue::Queue()
{
	front = NULL;
	rear = NULL;
}
Queue::element Queue::CreateElement()
{
	element object;
	cout << "Creating a new object" << endl;
	cout << "Name: ";
	cin >> object.name;
	cout << "Age: ";
	cin >> object.age;
	cout << endl;
	object.next = NULL;

	return object;
}

void Queue::EnQueue(element nElement)
{
	element* toAdd = new element;
	*toAdd = nElement;
	if (front == NULL)
		front = rear = toAdd;

	else
	{
		rear->next = toAdd;
		rear = toAdd;
	}
}

bool Queue::DeQueue()
{
	if (front != NULL)
	{
		if (front == rear)
		{
			delete front;
			front = NULL;
			rear = NULL;
		}
		else
		{
			auto temp = front;
			front = front->next;
			delete temp;
		}
		return true;

	}
	return false;
}

void Queue::DelAll()
{
	while (DeQueue());
}

void Queue::Display()
{
	if (front != NULL)
	{
		auto temp = front;
		while (temp != NULL)
		{
			cout << "Name: " << temp->name << ", age: " << temp->age << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	else
		cout << "Queue is empty!" << endl;
}