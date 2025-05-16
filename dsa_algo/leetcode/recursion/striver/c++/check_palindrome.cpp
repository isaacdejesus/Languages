#include<bits/stdc++.h>
bool f(std::string& str,int l)
{
    if(l >= str.size()/2)
        return true;
    if(str[l] != str[str.size() - l - 1])
        return false;
    return f(str,  l + 1);
}
int main()
{
    std::string s1 = "madam";
    std::cout<<f(s1, 0)<<'\n';
    std::string s2 = "potato";
    std::cout<<f(s2, 0)<<'\n';
}
