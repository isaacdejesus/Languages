#include <iostream>
#include <unordered_map>


int longestPalindrome(std::string );
int main()
{
    std::string str = "abccccdd";
    std::cout<<longestPalindrome(str);
    return 0;
}
int longestPalindrome(std::string s) {
        int sum = 0;    
        if(s.size() == 0)
            return sum;
        std::unordered_map<char, int> hash;
        int string_size = s.size();
        for(int i =0; i < string_size; i++)
        {
            hash[s[i]]++;
        }
        for(std::unordered_map<char,int>::iterator it = hash.begin(); it != hash.end(); ++it)
        {
            sum+= (it->second/2) * 2;  //int division will throw out decimal 1/2 -> 0 4/5-> 2
        }
        if(string_size > sum)
            return ++sum;
        return sum;
    }