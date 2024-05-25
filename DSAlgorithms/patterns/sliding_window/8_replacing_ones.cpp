#include <iostream>
#include <bits/stdc++.h>

class replacing_ones {
    public:
        static int find_length(const std::vector<int>& arr, int k)
        {
            int window_start = 0;
            int max_length = 0;
            int max_ones_count = 0;
            for(int window_end = 0; window_end < arr.size(); window_end++)
            {

                if(arr[window_end] == 1)
                    max_ones_count++;
                if(window_end - window_start + 1 - max_ones_count > k)
                {
                    if(arr[window_start] == 1)
                        max_ones_count--;
                    window_start++;
                }
            max_length = std::max(max_length, window_end - window_start + 1);
            }
            return max_length;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<replacing_ones::find_length(std::vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2)<<'\n';
    std::cout<<replacing_ones::find_length(std::vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3)<<'\n';
}

