class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> a_stack;
        for(int i = 0; i < operations.size(); i++)
        {
            std::string c = operations[i];
            if(c == "+")
            {
                std::cout<<a_stack.top();
                int right = a_stack.top();
                a_stack.pop();
                int left = a_stack.top();
                //std::cout<<left<<" : "<<right;
                a_stack.pop();
                a_stack.push(left);
                a_stack.push(right);
                a_stack.push(left + right);
            } 
            else if(c == "D")
            {
                int top = a_stack.top();
                a_stack.pop();
                a_stack.push(top);
                a_stack.push(2 * top);
            }
            else if(c == "C")
                a_stack.pop();
            else
            {
                a_stack.push(stoi(c));
                //std::cout<<a_stack.top()<<'\n';
            }
        }
        int result = 0;
        while(!a_stack.empty())
        {
            result += a_stack.top();
            a_stack.pop();
        }
        return result;
    }
};