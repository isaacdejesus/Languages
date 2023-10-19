class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int left = 0;
      int right = nums.size() - 1;
      int result = 0;
      while(left <= right)  
      {
          int mid = left + (right - left) /2;
          if((mid - 1 < 0 || nums[mid - 1] != nums[mid]) && (mid + 1 == nums.size() || nums[mid] != nums[mid + 1]))
          {
              int result = nums[mid];
              return nums[mid];
          }
          int left_size = mid;
          if(nums[mid - 1] == nums[mid])
            left_size = mid - 1;
          if(left_size % 2 == 0)
            left = mid + 1;
          else
            right = mid - 1;
      }
      return result;
    }
};