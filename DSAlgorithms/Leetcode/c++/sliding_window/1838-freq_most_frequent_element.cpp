class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int result = 0;
        long long total = 0;
        while(right < nums.size())
        {
            total+= nums[right];
            while(((long)(right - left + 1) * nums[right]) > total + k)
            {
                total -= nums[left];
                left++;
            }
            result = std::max(result, right - left + 1);
            right++;
        }
       return result;
    }
};