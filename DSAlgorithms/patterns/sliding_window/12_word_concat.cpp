#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

class word_concat 
{
    public:
        static std::vector<int> find_word_concat(const std::string &str, const std::vector<std::string> &words)
        {
            std::unordered_map<std::string, int> word_freq;
            for(auto word : words)
                word_freq[word]++;
            std::vector<int> result_indices;
            int words_count = words.size();
            int word_length = words[0].length();
            for(int i = 0; i <= str.length() - words_count * word_length; i++)
            {
                std::unordered_map<std::string, int> words_seen;
                for(int j = 0; j < words_count; j++)
                {
                    int next_word_index = i + j * word_length;
                    std::string word = str.substr(next_word_index, word_length) ;
                    if(word_freq.find(word) == word_freq.end())
                        break;
                    words_seen[word]++;
                    if(words_seen[word] > word_freq[word])
                        break;
                    if(j + 1 == words_count)
                        result_indices.push_back(i);
                }
            }
            return result_indices;
        }
};

int main(int argc, char *argv[])
{
    std::vector<int> result = word_concat::find_word_concat("catfoxcat", std::vector<std::string>{"cat", "fox"});
    for(auto num : result)
        std::cout<<num<<" ";
    std::cout<<'\n';
    result = word_concat::find_word_concat("catcatfoxfo", std::vector<std::string>{"cat", "fox"});
    for(auto num : result)
        std::cout<<num<<" ";
    std::cout<<'\n';
}
