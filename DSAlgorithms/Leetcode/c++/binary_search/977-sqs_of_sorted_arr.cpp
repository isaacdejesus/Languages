class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       std::vector<int> result; 
       int left = 0;
       int right = nums.size() - 1;
        while(left <= right)
        {
            if(nums[left] * nums[left] > nums[right] * nums[right])
            {
                result.push_back(nums[left] * nums[left]);
                left++;
            }
            else
            {
                result.push_back(nums[right] * nums[right]);
                right--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};