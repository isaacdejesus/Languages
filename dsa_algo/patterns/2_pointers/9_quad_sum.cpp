#include <bits/stdc++.h>
class quad_sum_target {
    public:
        static std::vector<std::vector<int>> search_quad(std::vector<int> &arr, int target)
        {
            std::sort(arr.begin(), arr.end());
            std::vector<std::vector<int>> quadruplets;
            for(int i = 0; i < arr.size() -3; i++)
            {
                if(i > 0 && arr[i] == arr[i - 1])
                    continue;
                for(int j = i + 1; j < arr.size() -2; j++)
                {
                    if(j > i + 1 && arr[j] == arr[j - 1])
                        continue;
                    search_pairs(arr, target, i, j, quadruplets);
                }
            }
            return quadruplets;
        }
    private: 
        static void search_pairs(const std::vector<int> &arr, int target_sum, int first, int second, std::vector<std::vector<int>> & quadruplets)
        {
            int left = second + 1;
            int right = arr.size() -1;
            while(left < right)
            {
                int sum = arr[first] + arr[second] + arr[left] + arr[right];
                if(sum == target_sum)
                {
                    quadruplets.push_back({arr[first], arr[second], arr[left], arr[right]});
                    left++;
                    right--;
                    while(left < right && arr[left] == arr[left - 1])
                        left++;
                    while(left < right && arr[right] == arr[right + 1])
                        right--;
                }
                else if(sum < target_sum)
                    left++;
                else
                    right--;
            }
        }
};
int main(int argc, char *argv[])
{
    std::vector<int> vec = {4, 1, 2, -1, 1, -3};
    auto result = quad_sum_target::search_quad(vec, 1);
    for(auto vec : result)
    {
        std::cout<<"[";
        for(auto num : vec)
            std::cout<<num<<" ";
        std::cout<<"]";
    }
    std::cout<<'\n';

    vec = {2, 0, -1, 1, -2, 2};
    result = quad_sum_target::search_quad(vec, 2);
    for(auto vec : result)
    {
        std::cout<<"[";
        for(auto num : vec)
            std::cout<<num<<" ";
        std::cout<<"]";
    }
    std::cout<<'\n';
}
