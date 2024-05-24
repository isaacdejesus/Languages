#include <iostream>
#include <bits/stdc++.h>
class max_sum_subarr
{
    public:
        static int find_max_sum_subarr(int k, const std::vector<int>& arr)
        {
            int max_sum = 0;
            int window_sum = 0;
            int window_start = 0;
            for(int window_end = 0; window_end < arr.size() ; window_end ++)
            {
                window_sum += arr[window_end];
                if(window_end >= k - 1)
                {
                    max_sum = std::max(max_sum, window_sum);
                    window_sum -= arr[window_start];
                    window_start++;
                }
            }
            return max_sum;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<"Max sum of a subarray of size k: "<<
        max_sum_subarr::find_max_sum_subarr(3, std::vector<int>{2, 1, 5, 1, 3, 2})<<'\n';
    std::cout<<"Max sum of a subarray of size k: "<<
        max_sum_subarr::find_max_sum_subarr(2, std::vector<int>{2, 3, 4, 1, 5})<<'\n';
}
