#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
	int size;
	int* q;
public:
	Queue();
	~Queue();
	void add(int a);
	void print();
	void deleteIndex(int b);
	void flip();
	Queue operator+(Queue obj);
	void FindElement(int c);
	void WriteInFile();
	void OpenFromFile();
	void DeleteQueue();
};

#endif