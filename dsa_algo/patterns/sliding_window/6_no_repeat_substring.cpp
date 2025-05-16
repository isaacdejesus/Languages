#include <iostream>
#include <bits/stdc++.h>
//lc #3
class no_repeat_substring {
    public:
        static int find_length(const std::string& str)
        {
            int l = 0;
            int longest = 0;
            std::unordered_map<char, int> char_index_map;
            for(int r = 0; r < str.length(); r++)
            {
                char right_char = str[r];
                if(char_index_map.count(right_char) > 0)
                    l = std::max(l, char_index_map[right_char] + 1);
                char_index_map[right_char] = r;
                longest = std::max(longest, r - l + 1);
            }
            return longest;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<"Length of longest substring: "<< no_repeat_substring::find_length("aabccbb")<<'\n';
    std::cout<<"Length of longest substring: "<< no_repeat_substring::find_length("abbbb")<<'\n';
    std::cout<<"Length of longest substring: "<< no_repeat_substring::find_length("abccde")<<'\n';
}

