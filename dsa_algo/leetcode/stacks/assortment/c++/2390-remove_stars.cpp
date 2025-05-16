class Solution {
public:
    string removeStars(string s) {
       std::stack<char> a_stack;
       for(int i = 0; i < s.size(); i++) 
       {
           if(s[i] != '*')
                a_stack.push(s[i]);
            else
                a_stack.pop();
       }
       std::string result = "";
       while(!a_stack.empty())
       {
           result += a_stack.top();
           a_stack.pop();
       }
       reverse(result.begin(), result.end());
       return result;
    }
};