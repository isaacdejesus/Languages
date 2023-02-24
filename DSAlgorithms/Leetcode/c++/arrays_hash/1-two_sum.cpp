std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> hash;
    int vector_size = nums.size();
    for(int index = 0; index < vector_size; index++)
    {
        int complement = target - nums[index];
        if(hash.count(complement))
            return {hash[complement], index};
        hash[nums[index]] = index;
    }
    return {};
}