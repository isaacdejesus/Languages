class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> a_stack;
        for(int i = 0; i < tokens.size(); i++)
        {
            std::string c = (tokens[i]);
            if(c == "+")
            {
                int right = a_stack.top();
                a_stack.pop();
                int left = a_stack.top();
                a_stack.pop();
                a_stack.push(left + right);
            }
            else if(c == "-")
            {
                int right = a_stack.top();
                a_stack.pop();
                int left = a_stack.top();
                a_stack.pop();
                a_stack.push(left - right);
            }
            else if(c == "*")
            {
                int right = a_stack.top();
                a_stack.pop();
                int left = a_stack.top();
                a_stack.pop();
                a_stack.push(left * right);
            }
            else if(c == "/")
            {
                int right = a_stack.top();
                a_stack.pop();
                int left = a_stack.top();
                a_stack.pop();
                a_stack.push(left / right);
            }
            else
            {
                a_stack.push(stoi(c));
            }
        }
        return a_stack.top();
    }
};