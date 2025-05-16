#include <bits/stdc++.h>
#include <iostream>
class pair_target_sum {
    public: 
        static std::pair<int, int> search(const std::vector<int> &arr, int target_sum)
        {
            int left = 0;
            int right = arr.size() - 1;
            while(left < right)
            {
                int current_sum = arr[left] + arr[right];
                if(current_sum == target_sum)
                    return std::make_pair(left, right);
                if(target_sum > current_sum)
                    left++;
                else 
                    right--;
            }
            return std::make_pair(-1, -1);
        }
};

int main(int argc, char *argv[])
{
    auto result = pair_target_sum::search(std::vector<int>{1, 2, 3, 4, 6}, 6);
    std::cout<<"Pair with target sum: [" << result.first <<", "<< result.second<< "]"<<'\n';
    result = pair_target_sum::search(std::vector<int>{ 2, 5, 9, 11}, 11);
    std::cout<<"Pair with target sum: [" << result.first <<", "<< result.second<< "]"<<'\n';
}

