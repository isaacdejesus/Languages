#include <iostream>

std::string encode(std::vector<std::string>& strs)
{
    std::string result = "";
    for(int i = 0; i < strs.size(); i++)
    {
        std::string str = strs[i];
        result += std::to_string(str.size()) + "#" + str;
    }
    return result;
}

std::vector<std::string> decode(std::string s)
{
    std::vector<std::string> result;
    int i = 0;
    while(i < s.size())
    {
        int j = i;
        while(s[j] != '#')
        {
            j++;
        }
        int length = stoi(s.substr(i, j - i));
        std::string str = s.substr(j + 1, length);
        result.push_back(str);
        i = j + 1 + length;
    }
    return result;
}