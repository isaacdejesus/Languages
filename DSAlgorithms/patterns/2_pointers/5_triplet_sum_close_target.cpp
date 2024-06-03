#include <iostream>
#include <bits/stdc++.h>
class triplet_sum_close_target
{
    public:
        static int search_triplet(std::vector<int>& arr, int target_sum)
        {
            std::sort(arr.begin(), arr.end());
            int smallest_dif = std::numeric_limits<int>::max();
            for(int i = 0; i < arr.size() - 2; i++)
            {
                int left = i + 1;
                int right = arr.size() - 1;
                while(left < right)
                {
                    int target_dif = target_sum - arr[i] - arr[left] - arr[right];
                    if(target_dif == 0)
                        return target_sum - target_dif;
                    if(std::abs(target_dif) < abs(smallest_dif))
                        smallest_dif = target_dif;
                    if(target_dif > 0)
                        left++;
                    else 
                        right--;
                }
            }
            return target_sum - smallest_dif;
        }
};
int main(int argc, char* argv[])
{
    std::vector<int> vec = {-2, 0, 1, 2};
    std::cout<<triplet_sum_close_target::search_triplet(vec, 2) << '\n';
    vec = {-3, -1, 1, 2};
    std::cout<<triplet_sum_close_target::search_triplet(vec, 1) << '\n';
    vec = {1, 0, 1, 1};
    std::cout<<triplet_sum_close_target::search_triplet(vec, 100) << '\n';
}
