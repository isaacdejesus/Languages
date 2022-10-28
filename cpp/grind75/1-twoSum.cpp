#include <iostream>
#include <vector>
#include <unordered_map>
std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::unordered_map<int, int> values;
    int len = nums.size();
    for(int i = 0; i < len; i++){
        int complement = target - nums[i];
        if(values.count(complement))
            return {values[complement], i};
    values[nums[i]] = i;
    }
    return {};
}
int main()
{
    return 0;
}
