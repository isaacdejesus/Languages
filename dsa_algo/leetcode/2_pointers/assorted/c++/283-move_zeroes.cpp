class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int insert_loc = 0;
       for(int iterator = 0; iterator < nums.size(); iterator++)
       {
           if(nums[iterator] != 0)
           {
               int temp = nums[insert_loc];
               nums[insert_loc] = nums[iterator];
               nums[iterator] = temp;
               insert_loc++;
           }
       }
    }
};