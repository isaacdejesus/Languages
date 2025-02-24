class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       std::unordered_map<int, int> hash = {{0, -1}};
       int total = 0;
       for(int i = 0; i < nums.size(); i++)
       {
           total += nums[i];
           int remainder = total % k;
           if(!(hash.count(remainder) > 0))
           {
               hash[remainder] = i;
           }
           else if(i - hash[remainder] > 1)
                return true;
       }
        return false;

    }
};