#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

class char_replacement 
{
    public: 
        static int find_length(const std::string &str, int k)
        {
            int window_start = 0;
            int max_length = 0;
            int max_repeated_letter_count = 0;
            std::unordered_map<char, int> letter_freq;
            for(int window_end = 0; window_end < str.length(); window_end++)
            {
                char right_char = str[window_end];
                letter_freq[right_char]++;
                max_repeated_letter_count = std::max(max_repeated_letter_count, letter_freq[right_char]);
                if(window_end - window_start + 1 - max_repeated_letter_count > k)
                {
                    char left_char = str[window_start];
                    letter_freq[left_char]--;
                    window_start++;
                }
                max_length = std::max(max_length, window_end - window_start + 1);
            }
            return max_length;
        }
};

int main(int argc, char *argv[])
{
    std::cout<<char_replacement::find_length("aabccbb", 2)<< '\n';
    std::cout<<char_replacement::find_length("abbcb", 1)<< '\n';
    std::cout<<char_replacement::find_length("abccde", 1)<< '\n';
}
