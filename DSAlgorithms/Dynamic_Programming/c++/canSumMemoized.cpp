#include <iostream>
#include <vector>
#include <unordered_map>
bool canSum(int, int[], int);
bool can_sum_memoized(int, std::vector<int>, std::unordered_map<int, bool>);
int main()
{
    int arr1[] = {2, 4};
    int arr2[] = {2, 3, 5, 7};
    std::cout<<canSum(7, arr1, 2);
    std::cout<<canSum(7, arr2, 4);
    std::vector<int> v = {2, 3, 5, 7};
    std::vector<int> v2 = {2, 4};
    std::unordered_map<int, bool> map;
    std::cout<<can_sum_memoized(7, v, map);
    map.clear();
    std::cout<<can_sum_memoized(7, v2, map);
    return 0;
}

bool canSum(int targetSum, int numbers[], int arrSize)
{
    if(targetSum == 0)
        return true;
    if(targetSum < 0)
        return false;
    for(int i = 0; i < arrSize; i++ )
    {
        int remainder = targetSum - numbers[i];
        if(canSum(remainder, numbers, arrSize) == true)
            return true;
    }
    return false;
}
bool can_sum_memoized(int target_sum, std::vector<int> numbers, std::unordered_map<int, bool> map)
{
    if(map.count(target_sum) > 0)
        return map[target_sum];

    if(target_sum == 0)
        return true;
    if(target_sum < 0)
        return false;
    for(int i = 0; i < numbers.size(); i ++)
    {
        int remainder = target_sum - numbers[i];
        if(can_sum_memoized(remainder, numbers, map) == true)
        {
            map[target_sum] = true;
            return true;
        }
    }
    return false;
}
