#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
class min_window_substring
{
    public:
        static std::string find_substring(const std::string &str, const std::string &pattern)
        {
            int window_start = 0;
            int matched = 0;
            int min_length = str.length() + 1;
            int substr_start = 0;
            std::unordered_map<char, int> char_freq;
            for(auto chr : pattern)
                char_freq[chr]++;
            for(int window_end = 0; window_end < str.length(); window_end++)
            {
                char right_char = str[window_end];
                if(char_freq.find(right_char) != char_freq.end())
                {
                    char_freq[right_char]--;
                    if(char_freq[right_char] >= 0)
                        matched++;
                }
                while(matched == pattern.length())
                {
                    if(min_length > window_end - window_start + 1)
                    {
                        min_length = window_end - window_start + 1;
                        substr_start = window_start;
                    }
                    char left_char = str[window_start++];
                    if(char_freq.find(left_char) != char_freq.end())
                    {
                        if(char_freq[left_char] == 0)
                            matched--;
                    }
                    char_freq[left_char]++;
                }
            }
            return min_length > str.length() ? "" : str.substr(substr_start, min_length);
        }
};

int main(int argc, char *argv[])
{
    std::cout<<min_window_substring::find_substring("aabdec", "abc")<< '\n';
    std::cout<<min_window_substring::find_substring("abdabca", "abc")<< '\n';
    std::cout<<min_window_substring::find_substring("adcad", "abc")<< '\n';
}
