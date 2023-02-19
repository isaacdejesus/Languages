#include <iostream>
#include <stack>
class Queue_using_stacks
{
    private: 
        std::stack<int> first;
        std::stack<int> second;
    public:
        void add(int item)
        {
            while(!first.empty())
            {
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            first.push(item);
            while(!second.empty())
            {
                int temp = second.top();
                second.pop();
                first.push(temp);
            }
        }
        void int remove()
        {
            return first.pop();
        }
        int peek()
        {
            return first.top();
        }
        bool isEmpty()
        {
            return first.empty();
        }
};
int main()
{

    return 0;
}