#include <iostream>
#include <vector>
#include <unordered_map>

int construct_count(std::string, std::vector<std::string>);
int construct_count_memoized(std::string, std::vector<std::string>, std::unordered_map<std::string, int>);
int main()
{
    std::vector<std::string> words = {"purp", "p", "ur", "le", "purpl"};
    std::cout<<construct_count("purple", words);
    std::cout<<'\n';
    return 0;
}

int construct_count(std::string target_word, std::vector<std::string> words)
{
    if(target_word == "")
        return 1;
    int count = 0;
    for(int word = 0; word < words.size(); word++)
    {
        if(target_word.find(words[word]) == 0)
        {
                int Rec_count = construct_count(target_word.substr(words[word].size()), words);
                count+= Rec_count;
       }
    }
    return count;
}

int construct_count_memoized(std::string target_word, std::vector<std::string> words, std::unordered_map<std::string, int> cache)
{
    if(cache.count(target_word) > 0)
        return cache[target_word];
    
    if(target_word == "")
        return 1;
    int count = 0;
    for(int word = 0; word < words.size(); word++)
    {
        if(target_word.find(words[word]) == 0)
        {
                int Rec_count = construct_count_memoized(target_word.substr(words[word].size()), words, cache);
                count+= Rec_count;
       }
    }
    cache[target_word] = count;
    return count;

}