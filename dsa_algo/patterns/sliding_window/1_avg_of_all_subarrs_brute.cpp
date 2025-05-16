#include <bits/stdc++.h>;
#include <iostream>
class avg_of_subarr_of_size_k {
    public:
        static std::vector<double> find_avgs(int k, const std::vector<int>& arr)
        {
            std::vector<double> result(arr.size() - k + 1);
            for(int i = 0; i <= arr.size() -k; i++)
            {
                double sum = 0;
                for(int j = i; j < i + k; j++)
                    sum += arr[j];
                result[i] = sum/k;
            }
            return result;
        }
};

int main(int argc, char* argv[])
{
    std::vector<double> result = avg_of_subarr_of_size_k::find_avgs(5, std::vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
    std::cout<<"Avg of subarrays of size k: ";
    for(double d: result)
        std::cout<< d <<" ";
    std::cout<<'\n';
}
