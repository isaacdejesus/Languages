class Solution {
public:
    string removeDuplicates(string s, int k) {
       std::stack<char> char_stack;
       std::stack<int> count_stack; 
       for(int i = 0; i < s.size(); i++)
       {
           if(!char_stack.empty() && char_stack.top() == s[i])
           {
               count_stack.top()++; //increment char count
           }
           else 
           {
              char_stack.push(s[i]);  //add to stack
              count_stack.push(1);    //add with value 1
           }
           if(count_stack.top() == k)  //if current char count == k
           {
               char_stack.pop();  //remove from stack
               count_stack.pop();  //remove from stack
           }
       }
       std::string result = "";
       while(!char_stack.empty())
       {
           std::string temp = "";
           for(int i = 0; i < count_stack.top(); i++)
                temp += char_stack.top();
           result = temp + result;
           char_stack.pop();
           count_stack.pop();
       }
       return result;
    }
};