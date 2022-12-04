#include <iostream>
#include <stack>

//creates stack with basic functionality of last in, first out
int main()
{
    //default constructor creates empty stack. Can also be used to copy existing stack
    std::stack<char> a_stack;

    //stack methods
    //empty() returns bool if stack is empty
    //size() returns current number of items in stack
    //top() returns reference to value at top of stack. Value can be modified
    a_stack.push(1);
    a_stack.push(5);
    a_stack.push(10);  //top of stack
    int top = a_stack.top();
    std::cout<<top<<'\n';
    a_stack.top() = -99;
    top = a_stack.top();
    std::cout<<top<<'\n';
    //push() adds new value to top of stack
    //pop() deletes value from top of stack
    a_stack.pop();

    return 0;
}