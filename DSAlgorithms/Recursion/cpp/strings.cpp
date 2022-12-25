#include <iostream>
#include <string>
#include <vector>

void remove_char(std::string &res, std::string input);
std::string remove_char(std::string);
std::string remove_word(std::string);
void subseq(std::string res, std::string input);
std::vector<std::string> subseq_vector(std:: string res, std::string input);
void subseq_ascii(std::string res, std::string input);
std::vector<std::string> subseq_ascii_vector(std::string res, std::string input);
int main()
{
    std::string str = "casas";
    std::string result = "";
    remove_char(result, str);
    std::cout<<result<<'\n';
    std::cout<<remove_char("lamas");
    std::cout<<remove_word("ihaveapples")<<'\n';
    result = "";
    std::string in = "abc";
    subseq(result, in);
    std::vector<std::string> string_subset = subseq_vector("", "abc");
    for(auto element: string_subset)
        std::cout<<element<<' ';
    std::cout<<'\n';
    subseq_ascii("", "abc");
    std::vector<std::string> ascii_subset = subseq_ascii_vector("", "abc");
    for(auto element: ascii_subset)
        std::cout<<element<<' ';
    std::cout<<'\n';

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
void subseq(std::string res , std::string input )
{
    if(input.empty())
    {
        std::cout<<res<<'\n';
        return;
    }
    subseq(res + input[0], input.substr(1));
    subseq(res, input.substr(1));
}
//same as above, except returns all sub sets inside a vector
std::vector<std::string> subseq_vector(std:: string res, std::string input)
{
   if(input.empty()) 
   {
        std::vector<std::string> result_vector;
        result_vector.push_back(res);
        return result_vector;
   }
   std::vector<std::string> left = subseq_vector(res + input[0], input.substr(1));
   std::vector<std::string> right = subseq_vector(res, input.substr(1));
   for(auto element: right)
        left.push_back(element);
   return left;
}
//print subsequence + ascii value
void subseq_ascii(std::string res, std::string input)
{
    if(input.empty())
    {
        std::cout<<res<<'\n';
        return;
    }
    subseq_ascii(res + input[0], input.substr(1));
    subseq_ascii(res , input.substr(1));
    subseq_ascii(res + std::to_string(input[0]+0), input.substr(1));
}
std::vector<std::string> subseq_ascii_vector(std::string res, std::string input)
{
   if(input.empty()) 
   {
        std::vector<std::string> result_vector;
        result_vector.push_back(res);
        return result_vector;
   }
   std::vector<std::string> first = subseq_ascii_vector(res + input[0], input.substr(1));
   std::vector<std::string> second = subseq_ascii_vector(res, input.substr(1));
   std::vector<std::string> third = subseq_ascii_vector(res + std::to_string(input[0]+0),input.substr(1));
   for(auto element: second)
        first.push_back(element);
   for(auto element: third)
       first.push_back(element);
   return first;
}
