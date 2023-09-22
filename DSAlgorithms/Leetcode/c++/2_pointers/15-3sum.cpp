class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       std::vector<std::vector<int>> result;
       sort(nums.begin(), nums.end());
       for(int i = 0; i < nums.size(); i ++)
       {
           if(i > 0 && nums[i] == nums[i - 1]) //check if value already used 
                continue;    //if yes, skip to next iteration
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int threesome = nums[i] + nums[left] + nums[right];
                if(threesome > 0)
                    right--;
                else if(threesome < 0)
                    left++;
                else
                {
                    std::vector<int> sub_result;
                    sub_result.push_back(nums[i]);
                    sub_result.push_back(nums[left]);
                    sub_result.push_back(nums[right]);
                    result.push_back(sub_result);
                    left++;
                    while(nums[left] == nums[left - 1] && left < right )
                        left++;
                }
            }
       }
       return result;
    }
};