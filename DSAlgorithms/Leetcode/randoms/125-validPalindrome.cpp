#include<iostream>

bool isPalindrome(std::string);
int main()
{
    std::cout<<isPalindrome("hannah")<<'\n';
    std::cout<<isPalindrome("sarah")<<'\n';
    return 0;
}
bool isPalindrome(std::string s)
{
    std::string alpha_string = "";
    int string_size = s.size();
    for(int character = 0; character < string_size; character++)
        if(isalnum(s[character]))
        {
            char c = tolower(s[character]);
            alpha_string+=c;
        }
    int end = alpha_string.size() - 1;
    for(int start = 0; start <= end; start++, end--)
        if(alpha_string[start] != alpha_string[end])
            return false;
    return true;
}

