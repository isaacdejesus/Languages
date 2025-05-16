class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        std::stack<int> val_stack; 
        std::stack<int> min_left_stack; 
        int current_min = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
           while(!val_stack.empty() && nums[i] >= val_stack.top()) 
           {
               val_stack.pop();
               min_left_stack.pop();
           }
           if(!val_stack.empty() && nums[i] < val_stack.top() && nums[i] > min_left_stack.top())
               return true;
            val_stack.push(nums[i]);
            min_left_stack.push(current_min);
            current_min = std::min(current_min, nums[i]);
        }
        return false;
    }
};