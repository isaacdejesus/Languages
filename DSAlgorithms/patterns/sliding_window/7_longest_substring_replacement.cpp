#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

class char_replacement 
{
    public: 
        static int find_length(const std::string &str, int k)
        {
            int l = 0;
            int longest = 0;
            int max_repeated_letter_count = 0;
            std::unordered_map<char, int> letter_freq;
            for(int r = 0; r < str.length(); r++)
            {
                char right_char = str[r];
                letter_freq[right_char]++;
                max_repeated_letter_count = std::max(max_repeated_letter_count, letter_freq[right_char]);
                if(r - l + 1 - max_repeated_letter_count > k)
                {
                    char left_char = str[l];
                    letter_freq[left_char]--;
                    l++;
                }
                longest = std::max(longest, r - l + 1);
            }
            return longest;
        }
};

int main(int argc, char *argv[])
{
    std::cout<<char_replacement::find_length("aabccbb", 2)<< '\n';
    std::cout<<char_replacement::find_length("abbcb", 1)<< '\n';
    std::cout<<char_replacement::find_length("abccde", 1)<< '\n';
}
