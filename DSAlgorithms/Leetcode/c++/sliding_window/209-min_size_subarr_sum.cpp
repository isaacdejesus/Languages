class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int left = 0;
       int total = 0;
       int result = std::numeric_limits<int>::max();
       for(int right = 0; right < nums.size(); right++)
       {
           total += nums[right];
           while(total >= target)
           {
               result = std::min(right - left + 1, result);
               total -= nums[left];
               left++;
           }
       }
       if(result == std::numeric_limits<int>::max())
            return 0;
        return result;
    }
};