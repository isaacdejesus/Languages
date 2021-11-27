#include<iostream>
#include<string>
#include<deque>


std::string check(std::string);
int main()
{
    std::string value = "haNnah";
    std::cout<<check(value)<<'\n';
    std::cout<<check("Thegreatpotatoman")<<'\n';
    return 0;
}

std::string check(std::string value)
{
       for(auto &character: value)
          character = tolower(character);

    std::deque<char> a_deque;
    for(auto character: value)
        a_deque.push_front(character);
    while(!a_deque.empty() && a_deque.front() == a_deque.back())
    {
        a_deque.pop_front();
        a_deque.pop_back();
    }
    if(a_deque.empty())
        return "It is a palindrome.";
    else return "Not a palindrome";

}
