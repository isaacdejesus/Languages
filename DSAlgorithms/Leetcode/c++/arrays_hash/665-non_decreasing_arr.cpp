class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] <= nums[i + 1])
                continue; //all good
            //if above fails, we check if changed is true, means we already changed once
            //and we need to change again bc condition failed
            if(changed == true) 
                return false;  
            if(i == 0 || nums[i + 1] >= nums[i - 1])
            {
                nums[i] = nums[i + 1];
                changed = true;
            }    
            else
            {
                nums[i + 1] = nums[i];
                changed = true;
            }
        }
        return true;
    }
};