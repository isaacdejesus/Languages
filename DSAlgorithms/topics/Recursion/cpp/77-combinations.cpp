//works but it is slow. Does not pass on lc
//coulnd't figure out how to memoize it -_-
#include<iostream>
#include<vector>
    std::vector<std::vector<int>> backtrack(int start, std::vector<int> sub_res, int k, int n)
    {
        if(start > n + 1)
            return {{}};

        if(sub_res.size() == k )
        {
            std::vector<std::vector<int>> result_vector;
            result_vector.push_back(sub_res);
            return result_vector;
        }
        sub_res.push_back(start);
        std::vector<std::vector<int>> left = backtrack(start + 1, sub_res, k, n);
        sub_res.pop_back();
        std::vector<std::vector<int>> right = backtrack(start + 1, sub_res, k, n);
        std::vector<std::vector<int>> res;
        for(auto element: left)
        {
            if(element.size() > 0)
                res.push_back(element);
        }
        for(auto element: right)
        {
            if(element.size() > 0)
                res.push_back(element);
        }
        return res;
    }
std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> res;
        return backtrack(1, res, k, n);
    }
int main()
{
    std::vector<std::vector<int>> result =  combine(20, 10);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            std::cout<<result[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    return 0;
}
