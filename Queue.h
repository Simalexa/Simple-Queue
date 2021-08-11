#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <iostream>
#include <fstream>

template <typename T>
class Queue
{
private:
	int sizeOfq;
public:
	//std::vector<T> q;
	T *q;
	~Queue();
	Queue();
	void add(T a);
	void print();
	void deleteIndex(int b);
	void FindElement(T c);
	void OpenFromFile();
	void DeleteQueue();
	void WriteInFile();
	void flip();
	Queue operator+(Queue obj);
};
template <typename T> Queue<T>::~Queue()
{
}
template <typename T> Queue<T>::Queue()
{
	sizeOfq = 0;
	q = new T[100];
}
template <typename T> void Queue<T>::add(T a)
{
	q[sizeOfq] = a;
	sizeOfq++;
}
template <typename T> void Queue<T>::print()
{
	for (int i = 0; i < sizeOfq; i++)
		std::cout << q[i] << " ";
	std::cout << std::endl;
}
template <typename T> void Queue<T>::deleteIndex(int b)
{
	if (b > sizeOfq)
		std::cout << "Error" << std::endl;
	else
	{
		for (int i = b; i < sizeOfq - 1; i++)
			q[i] = q[i + 1];
		sizeOfq--;
	}
}
template <typename T> void Queue<T>::FindElement(T c)
{
	for (int i = 0 ; i < sizeOfq ; i++)
		if (q[i] == c)
			std::cout << "Number in the row " << i << std::endl;
}
template <typename T> void Queue<T>::OpenFromFile()
{
	std::ifstream File;
	File.open("qu.txt");
	while (!File.eof())
	{
		File >> q[sizeOfq];
		sizeOfq++;
	}
	sizeOfq--;
}
template <typename T> void Queue<T>::DeleteQueue()
{
	delete[] q;
	sizeOfq = 0;
}
template <typename T> void Queue<T>::WriteInFile()
{
	std::ofstream File;
	File.open("qu.txt");
	for (int i = 0;i < sizeOfq;i++)
		File << q[i] << " ";
	File.close();
}
template <typename T> void Queue<T>::flip()
{
	T *q0 = new T [sizeOfq];
	for (int i = 0;i < sizeOfq;i++)
		q0[i] = q[i];
	for (int i = 0;i < sizeOfq;i++)
	{
		q[i] = q0[sizeOfq - i - 1];
	}
}
template <typename T> Queue<T> Queue<T>::operator+(Queue<T> obj)
{
	Queue res;
	for (int i = 0; i < sizeOfq; i++)
		res.add(q[i]);
	for (int i = 0; i < obj.sizeOfq; i++)
		res.add(obj.q[i]);
	return res;
}
#endif