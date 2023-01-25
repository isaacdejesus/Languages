#include <iostream>
#include <vector>
#include <unordered_map>

//std::vector<int> best_sum(int target, std::vector<int>, std::unordered_map<int, int>);
std::vector<int> best_sum(int , std::vector<int>);
int main()
{
    std::vector<int> v1 = {3, 5, 2};
    std::vector<int> result = best_sum(8, v1);
    for(auto item : result)
        std::cout<<item<<' ';
    std::cout<<'\n';
    return 0;
}
std::vector<int> best_sum(int target_sum, std::vector<int> numbers)
{
    if(target_sum == 0)
        return {};
    if(target_sum < 0)
        return {-1};
    
    std::vector<int> shortest_combination;
    for(int i = 0; i < numbers.size(); i++)
    {
        int remainder = target_sum - numbers[i];
        std::vector<int> remainder_combination = best_sum(remainder, numbers);
        if(remainder_combination.empty())
        {
            remainder_combination.push_back(numbers[i]);
            shortest_combination = remainder_combination;
        }
        if(!remainder_combination.empty() && remainder_combination[0] != -1)
        {
            remainder_combination.push_back(numbers[i]);
            if(shortest_combination.empty() || remainder_combination.size() < shortest_combination.size())
                shortest_combination = remainder_combination;
        }
    }
    
    return shortest_combination;
}
