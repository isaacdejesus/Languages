class Solution {
public:
    string removeKdigits(string num, int k) {
       std::stack<char> a_stack;
       if(num.size() <= k)
            return "0";
        if(k == 0)
            return num;
        std::string result = "";
        a_stack.push(num[0]);
       for(int i = 1; i < num.size(); ++i)
       {
           while(k > 0 && !a_stack.empty() && a_stack.top() > num[i])
           {
               k--;
               a_stack.pop();
           }
           a_stack.push(num[i]);
           if(a_stack.size() == 1 && num[i] == '0')
                a_stack.pop();
       }
       while(k && !a_stack.empty())
       {
           k--;
           a_stack.pop();
       }
       while(!a_stack.empty())
       {
           result.push_back(a_stack.top());
           a_stack.pop();
       }
       reverse(result.begin(), result.end());
       if(result.size() == 0)
            return "0";
        return result;
    }
};