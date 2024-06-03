#include <iostream>
#include <bits/stdc++.h>
class triplet_with_smaller_sum
{
    public:
        static std::vector<std::vector<int>> search_triplets(std::vector<int> &arr, int target)
        {
            std::sort(arr.begin(), arr.end());
            std::vector<std::vector<int>> triplets;
            for(int i = 0; i < arr.size() - 2; i++)
                search_pair(arr, target - arr[i], i, triplets);
            return triplets;
        }
    private: 
        static void search_pair(const std::vector<int> &arr, int target_sum, int first, std::vector<std::vector<int>> &triplets)
        {
            int left = first + 1;
            int right = arr.size() - 1;
            while(left < right)
            {
                if(arr[left] + arr[right] < target_sum)
                {
                    for(int i = right; i > left; i--)
                        triplets.push_back({arr[first], arr[left], arr[i]});
                    left++;
                }
                else
                    right--;
            }
        }
};
int main(int argc, char *argv[])
{
    std::vector<int> vec = {-1, 0, 2, 3};
    auto result = triplet_with_smaller_sum::search_triplets(vec, 3);
    for(auto vec: result)
    {
        std::cout<<"[";
        for(auto num : vec)
            std::cout<<num<<" ";
        std::cout<<"]";
    }
    std::cout<<'\n';
    vec = {-1, 4, 2, 1, 3};
    result = triplet_with_smaller_sum::search_triplets(vec, 5);
     for(auto vec: result)
    {
        std::cout<<"[";
        for(auto num : vec)
            std::cout<<num<<" ";
        std::cout<<"]";
    }
}
