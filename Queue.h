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
	std::vector<T> q;
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
	q.clear();
}
template <typename T> Queue<T>::Queue()
{
}
template <typename T> void Queue<T>::add(T a)
{
	q.push_back(a);
}
template <typename T> void Queue<T>::print()
{
	for (int i = 0; i < q.size(); i++)
		std::cout << q[i] << " ";
	std::cout << std::endl;
}
template <typename T> void Queue<T>::deleteIndex(int b)
{
	if (b > q.size())
		std::cout << "Error" << std::endl;
	else
		q.erase(q.begin() + b);
}
template <typename T> void Queue<T>::FindElement(T c)
{
	auto n = std::find(q.begin(), q.end(), c);
	std::cout << "Number in row "  << *n << std::endl;
}
template <typename T> void Queue<T>::OpenFromFile()
{
	std::ifstream File;
	T a;
	File.open("qu.txt");
	while (!File.eof())
	{
		File >> a;
		q.push_back(a);
	}
	q.pop_back();
}
template <typename T> void Queue<T>::DeleteQueue()
{
	q.clear();
}
template <typename T> void Queue<T>::WriteInFile()
{
	std::ofstream File;
	File.open("qu.txt");
	for (int i = 0;i < q.size();i++)
		File << q[i] << " ";
	File.close();
}
template <typename T> void Queue<T>::flip()
{
	std::vector<T> q0;
	for (int i = 0; i < q.size();i++)
		q0.push_back(q[i]);
	for (int i = 0;i < q.size();i++)
	{
		q[i] = q0[q.size() - i - 1];
	}
	q0.clear();
}
template <typename T> Queue<T> Queue<T>::operator+(Queue obj)
{
	Queue<T> res;
	for (int i = 0; i < q.size(); i++)
		res.add(q[i]);
	for (int i = 0; i < obj.q.size(); i++)
		res.add(obj.q[i]);
	return res;
}
#endif