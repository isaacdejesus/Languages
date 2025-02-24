class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int mod = pow(10, 9) + 7;
        int left = 0;
        int right = nums.size() - 1;
        //pows holds the powers of 2 values ranging from 0 to nums.size()
        //Recall left shift, << 1 is same as 2^num
        //if nums [3, 5, 6, 7]. pow holds [1, 2, 4, 8] or 2^0, 2^1, 2^2, 2^3
        //ugh left shift is weird
        //1 << val is same as 2 ^ val
        //val << 1 is same as val ^ 2
        //Here we are taking [i - 1] ^ 2 and storing it in [i]
        std::vector<int> pows(nums.size(), 1);
        for(int i = 1; i < nums.size(); i ++)
            pows[i] =(pows [i- 1] << 1) % mod;

        while(left <= right)
        {
            if((nums[left] + nums[right]) <= target)
            {
                result = (result + pows[right - left]) % mod;
                left++;
            }
            else
                right--;
        }
        return result;

    }
};