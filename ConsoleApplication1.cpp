#include <iostream>
#include "Queue.h"

int main()
{
    Queue q1;
    q1.OpenFromFile();
    q1.print();
    q1.DeleteQueue();
    q1.print();
    q1.add(1);
    q1.add(2);
    q1.add(3);
    q1.print();
    Queue q2;
    q2.add(4);
    q2.add(5);
    q2.add(6);
    q2.print();
    Queue q3=q1 + q2;
    q3.print();
    q3.flip();
    q3.print();
    q3.FindElement(6);
    q3.WriteInFile();
    return 0;
}
