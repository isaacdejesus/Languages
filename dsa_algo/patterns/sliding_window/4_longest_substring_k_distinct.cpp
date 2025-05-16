#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

class longest_substring_k_distinct {
    public:
        static int find_length(const std::string &str, int k)
        {
            int l = 0;
            int max_length = 0;
            std::unordered_map<char, int> char_freq_map;
            for(int r = 0; r < str.length(); r++)
            {
                char right_char = str[r];
                char_freq_map[right_char]++;
                while((int)char_freq_map.size() > k)
                {
                    char left_char = str[l];
                    char_freq_map[left_char]--;
                    if(char_freq_map[left_char]== 0)
                        char_freq_map.erase(left_char);
                    l++;
                }
                max_length = std::max(max_length, r - l + 1);
            }

            return max_length;
        }
};

int main(int argc, char *argv[])
{
    std::cout<<"Length of longest substring: "<< longest_substring_k_distinct::find_length("araaci", 2);
    std::cout<<'\n';
    std::cout<<"Length of longest substring: "<< longest_substring_k_distinct::find_length("araaci", 1);
    std::cout<<'\n';
    std::cout<<"Length of longest substring: "<< longest_substring_k_distinct::find_length("cbbebi", 3);
    std::cout<<'\n';
}

