class Solution {
public:
    bool can_split(int largest, std::vector<int>& nums, int m)
    {
        int sub_arr = 0;
        int current_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            current_sum += nums[i];
            if(current_sum > largest)
            {
                sub_arr++;
                current_sum = nums[i];
            }
        }
        return sub_arr + 1 <= m;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        for(int i = 0; i < nums.size(); i ++)
        {
           right += nums[i];
           left = std::max(left, nums[i]);
        }
        int result = right;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(can_split(mid, nums, k))
            {
                result = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return result;
        
    }
};