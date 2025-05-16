#include <iostream>
#include <queue>

int main()
{
    //constructor
    std::queue<int> a_queue;
    //empty() returns bool if queue is empty or not
    std::cout<<a_queue.empty();
    //size() return number of items in queue
    //push() adds new element at end of queue
    a_queue.push(1);
    a_queue.push(3);
    a_queue.push(5);
    a_queue.push(7);
    a_queue.push(9);
    //front() returns reference to oldest element/element at front of queue
    std::cout<<a_queue.front()<<'\n';
    //because it is a reference value can be changed
    a_queue.front() = -3;
    std::cout<<a_queue.front()<<'\n';
    //back() return a reference to newest element/element at back of queue
    std::cout<<a_queue.back()<<'\n';
    //pop() deletes the oldest element/ element at front of queue

    
    return 0;
}