class Solution {
public:
    string decodeString(string s) {
       std::string result = "";
       std::stack<std::string> a_stack;
       for(int i = 0; i < s.size(); i++) 
       {
           if(s[i] != ']')
           {
              std::string temp = "";
              temp = s[i];
              a_stack.push(temp);
           }
            else
                {
                    std::string temp = "";
                    while(!a_stack.empty() && a_stack.top() != "[")
                    {
                        temp = a_stack.top() + temp;
                        a_stack.pop();
                    }
                    a_stack.pop();
                    std::string k = "";
                    std::string top = a_stack.top();
                    while(!a_stack.empty() && isdigit(top[0]))
                    {
                        k = a_stack.top() + k;
                        a_stack.pop();
                        if(!a_stack.empty())
                            top = a_stack.top();
                    }
                    std::cout<<k;
                    int k_ = stoi(k);
                    for(int i = 0; i < k_; i++)
                        a_stack.push(temp);
                }  
       }
       while(!a_stack.empty())
        {
            result = a_stack.top() + result;
            a_stack.pop();
        }
        return result;
    }
};