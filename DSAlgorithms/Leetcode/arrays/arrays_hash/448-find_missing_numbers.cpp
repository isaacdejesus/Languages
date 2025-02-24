vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) 
    {
        int current = abs(nums[i]);
        nums[current - 1] = 0 - abs(nums[current - 1]);
    }
    std::vector<int> result;
    for(int i = 1; i <= nums.size(); i++)
        if(nums[i - 1] > 0)
            result.push_back(i);
    return result;
}