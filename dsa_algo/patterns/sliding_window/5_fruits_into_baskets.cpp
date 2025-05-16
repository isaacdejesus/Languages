#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
class fruits_into_baskets {
    public:
        static int find_length(const std::vector<char>& arr)
        {
            int l = 0;
            int max_length = 0;
            std::unordered_map<char, int> fruit_freq;
            for(int r = 0; r < arr.size(); r++)
            {
                fruit_freq[arr[r]]++;
                while((int)fruit_freq.size() > 2)
                {
                    fruit_freq[arr[l]]--;
                    if(fruit_freq[arr[l]] == 0)
                        fruit_freq.erase(arr[l]);
                    l++;
                }
                max_length = std::max(max_length, r - l + 1);
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
