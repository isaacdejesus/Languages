class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       int i = 0;
       long long int result = 0;
       while(i < nums.size()) 
       {
           int count = 0;
           while(i < nums.size() && nums[i] == 0)
           {
               count++;
               i++;
               result += count;
           }
           i++;
       }
       return result;
    }
};