#include <iostream>
#include <unordered_map>

bool isAnagram(std::string, std::string);
int main()
{
    std::cout<<isAnagram("rat", "car")<<'\n';
    std::cout<<isAnagram("anagram", "nagaram")<<'\n';
    return 0;
}
bool isAnagram(std::string s, std::string t)
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

