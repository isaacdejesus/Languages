#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
class fruits_into_baskets {
    public:
        static int find_length(const std::vector<char>& arr)
        {
            int window_start = 0;
            int max_length = 0;
            std::unordered_map<char, int> fruit_freq;
            for(int window_end = 0; window_end < arr.size(); window_end++)
            {
                fruit_freq[arr[window_end]]++;
                while((int)fruit_freq.size() > 2)
                {
                    fruit_freq[arr[window_start]]--;
                    if(fruit_freq[arr[window_start]] == 0)
                        fruit_freq.erase(arr[window_start]);
                    window_start++;
                }
                max_length = std::max(max_length, window_end - window_start + 1);
            }
            return max_length;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<"Max number of fruits: "<<
        fruits_into_baskets::find_length(std::vector<char>{'A', 'B', 'C', 'A', 'C'})<<'\n';
    std::cout<<"Max number of fruits: "<<
        fruits_into_baskets::find_length(std::vector<char>{'A', 'B', 'C', 'B', 'B', 'C'})<<'\n';
}
