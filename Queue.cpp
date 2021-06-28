#include <iostream>
#include <fstream>
#include "Queue.h"

Queue::Queue()
{
	size = 0;
	q = new int[100];
}

Queue::~Queue()
{
}

void Queue::add(int a)
{
	q[size] = a;
	size++;
}

void Queue::print()
{
	for (int i = 0;i < size;i++)
		std::cout << q[i]<< " ";
	std::cout << std::endl;
}

void Queue::deleteIndex(int b)
{
	if (b > size)
		std::cout << "Index larger then aueue length" << std::endl;
	else
	{
		for (int i = b; i < size - 1; i++)
			q[i] = q[i + 1];
		size--;
	}
}

Queue Queue::operator+(Queue obj)
{
	Queue res;
	for (int i = 0; i < size; i++)
		res.add(q[i]);
	for (int i = 0; i < obj.size; i++)
		res.add(obj.q[i]);
	return res;
}
void Queue::flip()
{
	int q0[100];
	for (int i = 0;i < size;i++)
		q0[i] = q[i];
	for (int i = 0;i < size;i++)
	{
		q[i] = q0[size - i - 1];
	}
}
void Queue::FindElement(int c)
{
	for (int i = 0;i < size;i++)
		if (q[i] == c)
			std::cout << "Number in row " << i << std::endl;
}
void Queue::OpenFromFile()
{
	if (size == 0)
	{
		std::ifstream File;
		int x;
		File.open("qu.txt");
		while (!File.eof())
		{
			File >> q[size];
			size++;
		}
		size--;
	}
	else
		std::cout << "Queue is full";
}
void Queue::WriteInFile()
{
	std::ofstream File;
	File.open("qu.txt");
	for (int i = 0;i < size;i++)
		File << q[i] << " ";
	File.close();
}
void Queue::DeleteQueue()
{
	delete q;
	size = 0;
}