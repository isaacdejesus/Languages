#include<iostream>
#include<unordered_map>
#include<vector>

std::vector<int> twoSum(std::vector<int>& nums, int target);
int main()
{
    std::vector<int> input_vector = {1, 3, 6, 5};
    std::vector<int> result_vector(twoSum(input_vector, 4));
    for(auto element: result_vector)
        std::cout<<element<<" ";
    std::cout<<'\n';
    return 0;
}

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