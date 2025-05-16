class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       std::stack<int> a_stack;
       int j = 0;
       for(int i = 0; i < pushed.size(); i++) 
       {
           a_stack.push(pushed[i]);
           while(j < popped.size() && !a_stack.empty() && popped[j] == a_stack.top())
           {
               a_stack.pop();
               j++;
           }
       }
       return a_stack.empty();
    }
};