class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       std::stack<int> temp_stack;
       std::stack<int> index_stack;  
       std::vector<int> result (temperatures.size(), 0);
       for(int i = 0; i < temperatures.size(); i++)
       {
           while(!temp_stack.empty() && temperatures[i] > temp_stack.top())
           {
               int temp = temp_stack.top();
               int index = index_stack.top();
               temp_stack.pop();
               index_stack.pop();
               result[index] = (i - index);
           }
           temp_stack.push(temperatures[i]);
           index_stack.push(i);
       }
       return result;
    }
};