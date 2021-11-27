#include <iostream>
#include "Queue.h"

int main()
{
    Queue<int> *q=new Queue<int>;
    q->enque(3);
    q->enque(5);
    q->enque(9);
    std::cout<<"deleting: "<<q->dequeue();
    std::cout<<"Value at Back of Queue is: "<<q->peekBack();
    std::cout<<'\n';
    std::cout<<"Value at the front of the Queue is: "<<q->peekFront();
    std::cout<<'\n';
    return 0;
}