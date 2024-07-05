#include <iostream>
#include <bits/stdc++.h>
#include <limits>
class min_subarr_sum {
    public:
        static int find_min_subarr(int s, const std::vector<int>& arr)
        {
            int window_sum = 0;
            int min_length = std::numeric_limits<int>::max();
            int l = 0;
            for(int r = 0; r < arr.size(); r++)
            {
                window_sum += arr[r];
                while(window_sum >= s)
                {
                    min_length = std::min(min_length, r - l + 1);
                    window_sum -= arr[l];
                    l++;
                }
            }
            return min_length == std::numeric_limits<int>::max() ? 0 : min_length;
        }
};

int main(int argc, char* argv[])
{
    int result = min_subarr_sum::find_min_subarr(7, std::vector<int>{2, 1, 5, 2, 3, 2});
    std::cout<<"Smallest subarray length: " << result <<'\n';
    result = min_subarr_sum::find_min_subarr(7, std::vector<int>{2, 1, 5, 2, 8});
    std::cout<<"Smallest subarray length: " << result <<'\n';
    result = min_subarr_sum::find_min_subarr(8, std::vector<int>{3, 4, 1, 1, 6});
    std::cout<<"Smallest subarray length: " << result <<'\n';
}
