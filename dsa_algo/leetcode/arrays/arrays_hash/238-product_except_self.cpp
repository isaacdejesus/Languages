class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size_of_arr = nums.size();    
        std::vector<int> result(size_of_arr, 1);
        int prefix = 1;
        for(int i = 0; i < size_of_arr; i++)
        {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for(int i = size_of_arr -1; i >= 0; i--)
        {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }
        return result;
    }
};