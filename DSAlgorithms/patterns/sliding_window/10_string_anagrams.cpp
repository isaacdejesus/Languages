#include <iostream>
#include <bits/stdc++.h>

class string_anagrams {
    public:
        static std::vector<int> find_string_anagrams(const std::string &str, const std::string &pattern)
        {
            int l = 0;
            int matched = 0;
            std::unordered_map<char, int> char_freq;
            for(auto chr : pattern)
                char_freq[chr]++;
            std::vector<int> result_indices;
            for(int r = 0; r < str.length(); r++)
            {
                char right_char = str[r];
                if(char_freq.count(right_char) > 0)
                {
                    char_freq[right_char]--;
                    if(char_freq[right_char] == 0)
                        matched ++;
                }
                if(matched == (int)char_freq.size())
                    result_indices.push_back(l);
                if(r >= pattern.length() - 1)
                {
                    char left_char = str[l++];
                    if(char_freq.count(left_char) > 0)
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
