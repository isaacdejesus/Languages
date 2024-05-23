#include <iostream>
#include <vector>
#include <unordered_map>

bool can_construct(std::string, std::vector<std::string>);
bool can_construct_memoized(std::string, std::vector<std::string>, std::unordered_map<std::string, bool>);
 
int main()
{
    std::vector<std::string> words1 = {"ab", "abc", "cd", "def", "abcd"};
    std::vector<std::string> words2 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
    std::cout<<can_construct("abcdef", words1);
    std::cout<<'\n';
    std::cout<<can_construct("skateboard", words2);
    std::cout<<'\n';
    return 0;
}
bool can_construct(std::string target_word, std::vector<std::string> words)
{
    if(target_word == "")
        return true;
    for(int word = 0; word < words.size(); word++)
    {
        if(target_word.find(words[word]) == 0)
        {
            std::string suffix = target_word.substr(words[word].size());
            if(can_construct(suffix, words) == true)
                return true;
        }
    }
    return false;
}
bool can_construct_memoized(std::string target_word, std::vector<std::string> words, std::unordered_map<std::string, bool> cache)
{
    if(cache.count(target_word) > 0)
        return cache[target_word];
    if(target_word == "")
        return true;
    for(int word = 0; word < words.size(); word++)
    {
        if(target_word.find(words[word]) == 0)
        {
            std::string suffix = target_word.substr(words[word].size());
            if(can_construct_memoized(suffix, words, cache) == true)
            {
                cache[target_word] = true;
                return true;
            }
        }
    }
    cache[target_word] = false;
    return false;

}