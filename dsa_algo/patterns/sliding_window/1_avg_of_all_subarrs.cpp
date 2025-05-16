#include <bits/stdc++.h>
#include <iostream>

class avg_of_subarr_size_k
{
    public:
        static std::vector<double> find_avg(int k, const std::vector<int>& arr)
        {
            std::vector<double> result(arr.size() -k + 1) ;
            double window_sum = 0;
            int l = 0;
            for(int r = 0; r < arr.size() ; r++)
            {
                window_sum += arr[r];
                if(r >= k - 1)
                {
                    result[l] = window_sum / k;
                    window_sum -= arr[l];
                    l++;
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
