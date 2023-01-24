#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> how_sum(int target_sum, std::vector<int>);
std::vector<int> how_sum_memoized(int target_sum, std::vector<int>, std::unordered_map<int, std::vector<int>>);
int main()
{
    std::vector<int> v1 = {3, 2, 1, 4};
    std::vector<int> result1 = how_sum(9, v1);
    for(auto item: result1)
        std::cout<<item<< ' ';
    std::cout<<'\n';
    std::unordered_map<int, std::vector<int>> map;
    std::vector<int> result2 = how_sum_memoized(9, v1, map);
    for(auto item: result2)
        std::cout<<item<< ' ';
    std::cout<<'\n';
    return 0;
}
std::vector<int> how_sum(int target_sum, std::vector<int> numbers)
{
    if(target_sum == 0)
        return {};
    if(target_sum < 0)
        return {-1};
    for(int i = 0; i < numbers.size(); i++)
    {
        int remainder = target_sum - numbers[i];
        std::vector<int> current_result = how_sum(remainder, numbers);
        current_result.push_back(numbers[i]);
        if(current_result[0] != -1)
        {
            return current_result;
        }
    }
    return {-1};
}
std::vector<int> how_sum_memoized(int target_sum, std::vector<int> numbers, std::unordered_map<int, std::vector<int>> cache)
{
    if(cache.count(target_sum) > 0)
        return cache[target_sum];
    if(target_sum == 0)
        return {};
    if(target_sum < 0)
        return {-1};
    for(int i = 0; i < numbers.size(); i++)
    {
        int remainder = target_sum - numbers[i];
        std::vector<int> current_result = how_sum(remainder, numbers);
        current_result.push_back(numbers[i]);
        if(current_result[0] != -1)
        {
            cache[target_sum] = current_result;
            return cache[target_sum];
        }
    }
    cache[target_sum] = {-1};
    return {-1};

}
