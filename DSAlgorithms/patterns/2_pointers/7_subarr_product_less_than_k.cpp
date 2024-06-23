#include <iostream>
#include <bits/stdc++.h>
class subarr_product_less_than_k {
    public:
        static std::vector<std::vector<int>> find_subarr(const std::vector<int>& arr, int target){
            std::vector<std::vector<int>> result;
            int product = 1;
            int left = 0;
            for(int right = 0; right < arr.size(); right++)
            {
                product *= arr[right];
                while(product >= target && left < arr.size())
                    product /= arr[left++];
                std::deque<int> temp_list;
                for(int i = right; i >= left; i--)
                {
                    temp_list.push_front(arr[i]);
                    std::vector<int> result_vec;
                    std::move(std::begin(temp_list), std::end(temp_list), std::back_inserter(result_vec));
                    result.push_back(result_vec);
                }
            }
            return result;
        }
};

int main(int argc, char* argv[])
{
    auto result = subarr_product_less_than_k::find_subarr(std::vector<int>{2, 5, 3, 10}, 30);
    for(auto vec : result)
    {
        std::cout<< "[";
        for(auto num : vec)
            std::cout<< num<< " ";
        std::cout<<"]";
    }
    std::cout<<'\n';

    result = subarr_product_less_than_k::find_subarr(std::vector<int>{8, 2, 6, 5}, 50);
    for(auto vec : result)
    {
        std::cout<< "[";
        for(auto num : vec)
            std::cout<< num<< " ";
        std::cout<<"]";
    }
    std::cout<<'\n';
}
