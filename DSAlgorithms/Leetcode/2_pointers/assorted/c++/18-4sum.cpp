class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(), nums.end());
       std::vector<std::vector<int>> result;
       for(int i = 0; i < nums.size(); i++)
       {
           if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
                    if(sum == target)
                    {
                        result.push_back(std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                    }
                    else if(sum > target)
                        right--;
                    else
                        left++;

                }
            }
       }
       return result;
    }
};