#include <iostream>
#include <string>
#include "stack.h"

int main() {
    Stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(5);
    std::cout<<stack.top();
    std::cout<<stack.pop();
    std::cout<<stack.top();
    return 0;
}