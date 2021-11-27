#include <iostream>
#include "arrayStack.h"
#include <string>

int main()
{
    arrayStack<int> stack(3);
    stack.push(7);
    stack.push(666);
    stack.push(9999);
    stack.push(1);
    std::cout<<stack.pop();
    std::cout<<stack.top();
    return 0;
}