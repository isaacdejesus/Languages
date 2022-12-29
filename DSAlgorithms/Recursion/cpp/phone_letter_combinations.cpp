#include <iostream>
#include <vector>
void pad(std::string, std::string);
std::vector<std::string> pad_vector(std::string, std::string);
int pad_count(std::string, std::string);
int main()
{
    pad("", "12");
    std::vector<std::string> pad_results = pad_vector("", "12");
    std::cout<<'\n';
    for(auto element: pad_results)
        std::cout<<element<< ' ';
    std::cout<<'\n';
    std::cout<<pad_count("", "12");
    std::cout<<'\n';
    return 0;
}
void pad(std::string sub_res, std::string input)
{
    if(input.empty())
    {
        std::cout<<sub_res<<' ';
        return;
    }
    int digit = input[0] - '0';  //converts '2' into 2
    for(int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char ch = (char) ('a' + i);
        pad(sub_res + ch, input.substr(1));
    }
}
std::vector<std::string> pad_vector(std::string sub_res, std::string input)
{
    if(input. empty())
    {
        std::vector<std::string> vec;
        vec.push_back(sub_res);
        return vec;
    }
    int digit = input[0] - '0';
    std::vector<std::string> results;
    for(int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char ch = (char) ('a' + i);
        std::vector<std::string> iter_res = pad_vector(sub_res + ch, input.substr(1));
        for(auto element: iter_res)
            results.push_back(element);
    }
    return results;
}
int pad_count(std::string sub_res, std::string input)
{
    if(input.empty())
        return 1;
    int count = 0;
    int digit = input[0] - '0';
    for(int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char ch = (char) ('a' + i);
        count = count + pad_count(sub_res + ch, input.substr(1));
    }
    return count;
}
