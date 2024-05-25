#include <iostream>
#include <bits/stdc++.h>

class string_anagrams {
    public:
        static std::vector<int> find_string_anagrams(const std::string &str, const std::string &pattern)
        {
            int window_start = 0;
            int matched = 0;
            std::unordered_map<char, int> char_freq;
            for(auto chr : pattern)
                char_freq[chr]++;
            std::vector<int> result_indices;
            for(int window_end = 0; window_end < str.length(); window_end++)
            {
                char right_char = str[window_end];
                if(char_freq.find(right_char) != char_freq.end())
                {
                    char_freq[right_char]--;
                    if(char_freq[right_char] == 0)
                        matched ++;
                }
                if(matched == (int)char_freq.size())
                    result_indices.push_back(window_start);
                if(window_end >= pattern.length() - 1)
                {
                    char left_char = str[window_start++];
                    if(char_freq.find(left_char) != char_freq.end())
                    {
                        if(char_freq[left_char] == 0)
                            matched --;
                        char_freq[left_char]++;
                    }

                }
            }
            return result_indices;
        }
};

int main(int argc, char *argv[])
{
    auto result = string_anagrams::find_string_anagrams("ppqp", "pq");
    for(auto num : result)
        std::cout<<num<<" ";
    std::cout<<'\n';
    result = string_anagrams::find_string_anagrams("abbcabc", "abc");
    for(auto num : result)
        std::cout<<num<<" ";
    std::cout<<'\n';
}
