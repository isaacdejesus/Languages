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
            first.push(item);
        }
        void int remove()
        {
            while(!first.empty())
            {
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            int removed = second.top();
            second.pop();
            while(!second.empty())
            {
                int temp = second.top();
                second.pop();
                first.push(temp);
            }
            return removed;
        }
        int peek()
        {
            while(!first.empty())
            {
                int temp = first.top();
                first.pop();
                second.push(temp);
            }
            int peeked = second.top();
            while(!second.empty())
            {
                int temp = second.top();
                second.pop();
                first.push(temp);
            }
            return peeked;
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