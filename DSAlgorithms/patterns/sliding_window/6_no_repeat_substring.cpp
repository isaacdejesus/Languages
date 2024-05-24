#include <iostream>
#include <bits/stdc++.h>

class no_repeat_substring {
    public:
        static int find_length(const std::string& str)
        {
            int window_start = 0;
            int max_length = 0;
            std::unordered_map<char, int> char_index_map;
            for(int window_end = 0; window_end < str.length(); window_end++)
            {
                char right_char = str[window_end];
                if(char_index_map.find(right_char) != char_index_map.end())
                    window_start = std::max(window_start, char_index_map[right_char] + 1);
                char_index_map[right_char] = window_end;
                max_length = std::max(max_length, window_end - window_start + 1);
            }
            return max_length;
        }
};

int main(int argc, char* argv[])
{
    std::cout<<"Length of longest substring: "<< no_repeat_substring::find_length("aabccbb")<<'\n';
    std::cout<<"Length of longest substring: "<< no_repeat_substring::find_length("abbbb")<<'\n';
    std::cout<<"Length of longest substring: "<< no_repeat_substring::find_length("abccde")<<'\n';
}

