class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       std::sort(nums.begin(), nums.end());
       int left = 0;
       int right = k - 1;
        //requires #include <limits>
        int result =  std::numeric_limits<int>::max();
        while(right < nums.size())
        {
            result = std::min(result, nums[right] - nums[left]);
            left ++;
            right++;
        }
        return result;
    }
};