class Solution {
public:
    int search(vector<int>& nums, int target) {
       int left = 0;
       int right = nums.size() - 1;
       while(left <= right) 
       {
            int mid = left + (right - left) /2 ;
            if(target == nums[mid]) //left sorted portion
                return mid;
            if(nums[left] <= nums[mid])
                if(target > nums[mid] || target < nums[left])
                    left = mid + 1;
                else 
                    right = mid - 1;
            else  //right sorted portion
                if(target < nums[mid] || target > nums[right])
                    right = mid - 1;
                else 
                    left = mid + 1;
       }
       return -1;
    }
};