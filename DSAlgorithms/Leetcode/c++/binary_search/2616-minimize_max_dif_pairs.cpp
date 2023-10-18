class Solution {
public:
    bool is_valid(int threshold, int p, std::vector<int>& nums)
    {
        int i = 0;
        int count = 0;
        while(i < nums.size() - 1)
        {
            if(abs(nums[i] - nums[i + 1]) <= threshold)
            {
                count++;
                i +=2;
            }
            else
                i++;
            if(count == p)
                return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = pow(10, 9);
        int result = 0;
        while(left <= right)
        {
            int mid = left + (right - left) /2;
            if(is_valid(mid, p, nums))
            {
                result = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return result;
    }
};