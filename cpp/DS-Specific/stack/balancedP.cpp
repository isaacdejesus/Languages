#include<iostream>
#include<string>
#include<stack>
//checks if a sequence of parenthesis is balanced.
bool checkBalanced(std::string);

int main()
{
    std::string balancedString = "[{([])()}]";
    std::string notBalancedString = "{([[}]])}";
    std::cout<<checkBalanced(balancedString)<<'\n';
    std::cout<<checkBalanced(notBalancedString)<<'\n';
    

    return 0;
}

bool checkBalanced(std::string str)
{
    bool isBalanced = false;
    std::stack<char> a_stack;
    for( auto character: str)
    {
        if(character == '(' || character == '[' || character == '{')
            a_stack.push(character);
        else if(character == ']' || character == '}' || character == ')')
            a_stack.pop();
    }
    if(a_stack.empty())
        isBalanced = true;

     return isBalanced;
}
