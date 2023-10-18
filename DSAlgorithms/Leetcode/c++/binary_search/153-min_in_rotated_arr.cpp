class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            if(nums[left] < nums[right])
            {
                result = std::min(result, nums[left]);
                break;
            }
            int mid = left + (right - left) /2; 
            result = std::min(result, nums[mid]);
            if(nums[mid] >= nums[left])
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return result;
    }
};