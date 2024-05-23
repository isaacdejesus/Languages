#include <bits/stdc++.h>
#include <iostream>

class avg_of_subarr_size_k
{
    public:
        static std::vector<double> find_avg(int k, const std::vector<int>& arr)
        {
            std::vector<double> result(arr.size() -k + 1) ;
            double window_sum = 0;
            int window_start = 0;
            for(int window_end = 0; window_end < arr.size() ; window_end++)
            {
                window_sum += arr[window_end];
                if(window_end >= k - 1)
                {
                    result[window_start] = window_sum / k;
                    window_sum -= arr[window_start];
                    window_start++;
                }
            }
            return result;
        }
};

int main(int argc, char* args[])
{
    std::vector<double> result = avg_of_subarr_size_k::find_avg(5, std::vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
    std::cout<<"avgs of subarrays of size k: ";
    for(double d : result)
        std::cout<< d << " ";
    std::cout<< '\n';
}
