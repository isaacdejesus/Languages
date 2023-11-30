//alvyn the coder combinations but doesn't work?
#include <iostream>
#include <vector>
std::vector<std::vector<char>> combinations(std::vector<char>& arr)
{
    if(arr.size() == 0)
    {
        std::vector<std::vector<char>> current_res; //empty 2d vec
        return current_res;  //return empty 2d vec
    }
    char first_element = arr[0]; 
    std::vector<char> remaining_elements(arr.begin() + 1, arr.end());
    std::vector<std::vector<char>> combinations_without_first = combinations(remaining_elements);
    std::vector<std::vector<char>> combinations_with_first;
    std::vector<std::vector<char>> sub_result;
    for(auto comb: combinations_without_first)
    {
        sub_result.push_back(comb);
        std::vector<char> with_first = comb;
        with_first.push_back(first_element);
        sub_result.push_back(with_first);
        //std::vector<char> comb_with_first(combinations_without_first[i].begin(), combinations_without_first[i].end());
        //std::vector<char> comb_with_first = combinations_without_first[i];
        //comb_with_first.push_back(first_element);
        //combinations_with_first.push_back(comb_with_first);
    }
    /*
    std::vector<std::vector<char>> sub_result;
    for(int i = 0; i < combinations_without_first.size(); i++)
        sub_result.push_back(combinations_without_first[i]);
    for(int i = 0; i < combinations_with_first.size(); i++)
        sub_result.push_back(combinations_with_first[i]);
    return sub_result;
    */
    return sub_result;
}
int main()
{
    std::vector<char> vec = {'a', 'b', 'c'};
    std::vector<std::vector<char>> result = combinations(vec);
    std::cout<<result.size();
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            std::cout<<result[i][j];
        }
        std::cout<<'\n';
    }
    return 0;
}

