#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
class min_window_substring
{
    public:
        static std::string find_substring(const std::string &str, const std::string &pattern)
        {
            int l = 0;
            int matched = 0;
            int min_length = str.length() + 1;
            int substr_start = 0;
            std::unordered_map<char, int> char_freq;
            for(auto chr : pattern)
                char_freq[chr]++;
            for(int r = 0; r < str.length(); r++)
            {
                char right_char = str[r];
                if(char_freq.count(right_char) > 0 )
                {
                    char_freq[right_char]--;
                    if(char_freq[right_char] >= 0)
                        matched++;
                }
                while(matched == pattern.length())
                {
                    if(min_length > r - l + 1)
                    {
                        min_length = r - l + 1;
                        substr_start = l;
                    }
                    char left_char = str[l++];
                    if(char_freq.count(left_char) > 0)
                    {
                        if(char_freq[left_char] == 0)
                            matched--;
                    }
                    char_freq[left_char]++;  //add char back to hash since it is going out of window
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
