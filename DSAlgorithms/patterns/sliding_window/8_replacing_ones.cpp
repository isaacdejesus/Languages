#include <iostream>
#include <bits/stdc++.h>

class replacing_ones {
    public:
        static int find_length(const std::vector<int>& arr, int k)
        {
            int l = 0;
            int max_length = 0;
            int max_ones_count = 0;
            for(int r = 0; r < arr.size(); r++)
            {

                if(arr[r] == 1)
                    max_ones_count++;
                if(r - l + 1 - max_ones_count > k)
                {
                    if(arr[l] == 1)
                        max_ones_count--;
                    l++;
                }
            max_length = std::max(max_length, r - l + 1);
            }
            return max_length;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<replacing_ones::find_length(std::vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2)<<'\n';
    std::cout<<replacing_ones::find_length(std::vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3)<<'\n';
}

