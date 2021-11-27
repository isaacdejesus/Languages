#include <iostream>
#include <string>
#include "arrayQueue.h"

int main()
{
    arrayQueue<int> *queue=new arrayQueue<int>(10);
    queue->enqueue(2);
    queue->enqueue(9);
    queue->enqueue(11);
    queue->enqueue(15);
    std::cout<<"At the back of Queue: "<<queue->back();
    std::cout<<'\n';
    std::cout<<"At front of Queue: "<<queue->front();
    std::cout<<'\n';
    std::cout<<queue->dequeue();
    std::cout<<'\n';
    queue->displayAll();
    std::cout<<"Current size of the Queue is: "<<queue->getCurrentSize()<<'\n';
    return 0;
}