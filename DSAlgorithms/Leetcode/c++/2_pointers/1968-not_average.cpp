class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       std::vector<int> result;
       int left = 0;
       int right = nums.size() - 1;
       while(result.size() != nums.size())
       {
           result.push_back(nums[left]);
           left++;
           if(left <= right)
           {
               result.push_back(nums[right]);
               right--;
           }
       }
       return result;
    }
};