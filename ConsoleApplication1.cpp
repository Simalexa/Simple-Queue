#include "Queue.h"

int main()
{
    Queue<int> q1;
    q1.print();
    q1.add(1);
    q1.add(2);
    q1.add(3);
    q1.print();
    Queue<int> q2;
    q2.add(4);
    q2.add(5);
    q2.add(6);
    q2.print();
    Queue<int> q3 = q1 + q2;
    q3.print();
    q3.flip();
    q3.print();
    Queue<char> q4;
    q4.add('a');
    Queue<char> q5;
    q4.add('b');
    Queue<char> q6 = q4 + q5;
    q4.print();
    return 0;
}
