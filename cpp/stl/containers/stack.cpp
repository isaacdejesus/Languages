#include <iostream>
#include <stack>
int main()
{
    //declare a stack
    std::stack<int> a_stack;
    a_stack.push(0);
    a_stack.push(1);
    a_stack.push(2);
    a_stack.push(3);
    a_stack.push(4);
    a_stack.push(5);
    //has size() and empty()
    while(!a_stack.empty())
    {
        std::cout<<a_stack.top()<<' ';
        a_stack.pop();
    }
    return 0;
}
