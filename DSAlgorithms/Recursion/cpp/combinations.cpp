#include <iostream>
#include <vector>
std::vector<std::vector<char>> combinations(std::vector<char> res, std::vector<char> arr)
{
    if(arr.size() == 0)
    {
        std::vector<std::vector<char>> result_vector;
        result_vector.push_back(res);
        return result_vector;
    }
    char first = arr[0];
    std::vector<char> remainder(arr.begin() + 1, arr.end());
    std::vector<std::vector<char>> left = combinations(res, remainder);
    res.push_back(first);
    std::vector<std::vector<char>> right = combinations(res, remainder);
    for(auto element: right)
        left.push_back(element);
    return left;
}
int main()
{
    std::vector<char> vec = {'a', 'b', 'c'};
    std::vector<char> r;
    std::vector<std::vector<char>> result = combinations(r, vec);
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

