#include <iostream>
#include <string>

void remove_char(std::string &res, std::string input);
std::string remove_char(std::string);
std::string remove_word(std::string);
int main()
{
    std::string str = "casas";
    std::string result = "";
    remove_char(result, str);
    std::cout<<result<<'\n';
    std::cout<<remove_char("lamas");
    //std::cout<<remove_word("ihaveapples");
    return 0;
}
void remove_char(std::string &res, std::string input)
{
    if(input.empty())
        return;
    if(input[0] == 'a')
        remove_char(res, input.substr(1));
    else
        remove_char(res+= input[0], input.substr(1));
}
std::string remove_char(std::string input)
{
    if(input.empty())
        return "";
    if(input[0] == 'a')
        return remove_char(input.substr(1));
    else
        return input[0] + remove_char(input.substr(1));
}
std::string remove_word(std::string input)
{
    if(input.empty())
        return "";
    if(input.starts_with("apple")) //requires c++20
        return remove_word(input.substr(5));
    else
        return input[0] + remove_word(input.substr(1));
}