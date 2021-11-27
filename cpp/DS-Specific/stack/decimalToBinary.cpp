#include<iostream>
#include<stack>
#include<string>

std::string getBinary(int);
int main()
{
    int number = 233;
    std::cout<<getBinary(number)<<'\n';
    return 0;
}

std::string getBinary(int num)
{
    std::stack<int> a_stack;
    std::string returnString = {};
    while(num > 0)
    {   
        //get remainder
        int remainder = num%2;
        //add to stack
        a_stack.push(remainder);
        num = num/2;
    }
    while(!a_stack.empty())
    {
        returnString.append(std::to_string(a_stack.top()));
        //std::cout<<a_stack.top();
        a_stack.pop();
    }
    return returnString ;
}
