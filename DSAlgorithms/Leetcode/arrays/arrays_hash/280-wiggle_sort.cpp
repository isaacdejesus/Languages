void wiggle_sort(std::vector<int>& nums)
{
    for(int i = 1; i < nums.size(); i ++)
    {
        if(i % 2 == 1 && nums[i] < nums[i - 1])
        {
            int temp = nums[i - 1];
            nums[i - 1] = nums[i];
            nums[i] = temp;
        }
        if(i % 2 == 0 && nums[i] > nums[i - 1])
        {
            int temp = nums[i - 1]
            nums[i - 1] =  nums[i];
            nums[i] = temp;
        }
    }
    return nums;
}