class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int insert_loc = 1;
       for(int i = 1; i < nums.size(); i++) 
       {
           if(nums[i] != nums[i - 1])
           {
               nums[insert_loc] = nums[i];
               insert_loc++;
           }
       }
       return insert_loc;
    }
};