#include <iostream>
#include <unordered_map>

bool is_anagram(std::string, std::string);
bool is_anagram2(std::string s, std::string t);
bool is_anagram3(std::string s, std::string t);
int main()
{
    std::cout<<isAnagram("rat", "car")<<'\n';
    std::cout<<isAnagram("anagram", "nagaram")<<'\n';
    return 0;
}
bool is_anagram(std::string s, std::string t)
{
    int sLength = s.length();
    int tLength = t.length();
    if(sLength != tLength)
        return false;
    std::unordered_map<char, int> hash;
    for(int character = 0; character < sLength; character++)
        hash[s[character]]++;
    for(int character = 0; character < tLength; character++)
        if(hash[t[character]] <= 0)
            return false;
        else
            hash[t[character]]--;
    return true;
}
    
bool is_anagram2(string s, string t) {
    if(s.size() != t.size())
        return false;
    std::unordered_map<char, int> s_hash;
    std::unordered_map<char, int> t_hash;
    for(int i = 0; i < s.size(); i++)
        s_hash[s[i]]++;
    for(int i = 0; i < t.size(); i++)
        t_hash[t[i]]++;
    for(const auto &[key, value]: s_hash)
        if(value != t_hash[key])
            return false;
    return true;
    }
bool is_anagram3(std::string s, std::string t)
{
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
}