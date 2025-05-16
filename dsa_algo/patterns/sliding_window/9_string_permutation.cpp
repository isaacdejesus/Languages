#include <iostream>
#include <bits/stdc++.h>

class string_permutation {
    public:
        static bool find_permutation(const std::string &str, const std::string &pattern)
        {
            int l = 0;
            int matched = 0;
            std::unordered_map<char, int> char_freq;
            for(auto chr : pattern)
                char_freq[chr]++;
            for(int r = 0; r < str.length(); r++)
            {
                char right_char = str[r];
                if(char_freq.count(right_char) > 0)
                {
                    char_freq[right_char]--;
                    if(char_freq[right_char] == 0)
                        matched++;
                }
                if(matched == (int)char_freq.size())
                    return true;
                if(r >= pattern.length() - 1)
                {
                    char left_char = str[l++];
                    if(char_freq.count(left_char) > 0)
                    {
                        if(char_freq[left_char] == 0)
                            matched--;
                        char_freq[left_char]++;
                    }
                }
            }

            return false;
        }
};

int main(int argc, char *argv[])
{
    std::cout<<"Permutation exist: "<<string_permutation::find_permutation("oidbcaf", "abc")<<'\n';
    std::cout<<"Permutation exist: "<<string_permutation::find_permutation("odicf", "dc")<<'\n';
    std::cout<<"Permutation exist: "<<string_permutation::find_permutation("bcdxabcdy", "bcdyabcdx")<<'\n';
    std::cout<<"Permutation exist: "<<string_permutation::find_permutation("aaacb", "abc")<<'\n';
}
