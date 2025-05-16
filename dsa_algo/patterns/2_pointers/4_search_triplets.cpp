#include <iostream>
#include <bits/stdc++.h>

class triplet_sum_zero
{
    public:
        static std::vector<std::vector<int>> search_triplets(std::vector<int> &arr)
        {
            std::sort(arr.begin(), arr.end());
            std::vector<std::vector<int>> triplets;
            for(int i = 0; i < arr.size() - 2; i++)
            {
                if(i > 0 && arr[i] == arr[i - 1])
                    continue;
                search_pair(arr, -arr[i], i + 1, triplets);
            }
            return triplets;
        }
    private:
        static void search_pair(const std::vector<int> &arr, int target_sum, int left, std::vector<std::vector<int>> &triplets)
        {
            int right = arr.size() - 1;
            while(left < right)
            {
                int current_sum = arr[left] + arr[right];
                if(current_sum == target_sum)
                {
                    triplets.push_back({-target_sum, arr[left], arr[right]});
                    left++;
                    right--;
                    while(left < right && arr[left] == arr[left - 1])
                        left++;
                    while(left < right && arr[right] == arr[right + 1])
                        right--;
                }
                else if(target_sum > current_sum)
                    left++;
                else
                    right--;
            }
        }
};
int main(int argc, char *argv[])
{
    std::vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
    auto result = triplet_sum_zero::search_triplets(vec);
    for(auto vec : result)
    {
        std::cout<< "[";
        for(auto num : vec)
            std::cout<< num <<" ";
        std::cout<<"]";
    }
    std::cout<<'\n';
    vec = {-5, 2, -1, -2, 3};
    result = triplet_sum_zero::search_triplets(vec);
    for(auto vec : result)
    {
        std::cout<< "[";
        for(auto num : vec)
            std::cout<< num <<" ";
        std::cout<<"]";
    }
    std::cout<<'\n';
        
}
