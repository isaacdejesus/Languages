#include <iostream>
#include <queue>
#include "functions.h"
int main()
{
    std::queue<std::string> a_queue;
    // push add elements to queue
    a_queue.push("lol");
    a_queue.push("the");
    a_queue.push(" great potato");
    a_queue.push(" man strikes again!");
    //pop removes element from queue
    a_queue.pop();
    //front() returns element at front of queue
    print_ln(a_queue.front());
    //back() returns element at back of queue
    print_ln(a_queue.back());
    //empty checks if queue is empty
    //size returns size of queue
    if(a_queue.empty())
        print_ln("queue is empty!");
    else
        std::cout<<"queue contains"<<a_queue.size()<<" elements"<<'\n';
    //copy constructor can make copy of another queue
    std::queue<std::string> copy_a_queue (a_queue);

    //priority queue places the max element to the top
    //functions: empty, size, top, push, pop
    std::priority_queue<int> p_queue;
    p_queue.push(0);
    p_queue.push(33);
    p_queue.push(99);
    p_queue.push(16);
    p_queue.push(839);

    while(!p_queue.empty())
    {
        std::cout<<p_queue.top()<<'\n';
        p_queue.pop();
    }
    return 0;
}

