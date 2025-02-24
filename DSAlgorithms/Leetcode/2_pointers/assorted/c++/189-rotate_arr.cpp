class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();      
        int left = 0; 
        int right = nums.size() - 1;
        while(left < right) //reverse entire arr
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] =  temp;
            left ++;
            right --;
        }
        left = 0;
        right = k - 1;
        while(left < right) //reverse from start to k
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] =  temp;
            left ++;
            right --;
        }
        left = k;
        right = nums.size() - 1;
        while(left < right) // reverse from k to end
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] =  temp;
            left ++;
            right --;
        }
    }
};