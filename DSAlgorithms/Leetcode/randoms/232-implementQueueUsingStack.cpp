#include <iostream>
#include <stack>
class Queue {
    private:
        std::stack<int> stack_in;
        std::stack<int> stack_out;
    public:
        Queue(){};
        void push(int x){
            stack_in.push(x);
        }
        int pop()
        {
            peek();
            int val = stack_out.top();
            stack_out.pop();
            return val;
        }

        int peek()
        {
            if(stack_out.empty())
                while(!stack_in.empty())
                {
                    stack_out.push(stack_in.top());
                    stack_in.pop();
                }
            return stack_out.top();
        }

        bool empty()
        {
            return stack_in.empty() && stack_out.empty();
        }
        
};