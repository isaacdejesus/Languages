#include <iostream>
#include <vector>
void permutations(std::string, std::string);
std::vector<std::string> permutations_vector(std::string, std::string);
int permutations_count(std::string, std::string);
int main()
{
    permutations("", "abc");
    std::cout<<'\n';
    std::vector<std::string> permunation_vec = permutations_vector("", "abc");
    for(auto element: permunation_vec)
        std::cout<<element<<' ';
    std::cout<<'\n';
    std::cout<<permutations_count("", "abc");
    std::cout<<'\n';
    return 0;
}
void permutations(std::string sub_result, std::string input)
{
    if(input.empty())    
    {
        std::cout<<sub_result<<'\n';
        return;
    }
    for(int i = 0; i <= sub_result.size(); i++)
    {
        std::string first = sub_result.substr(0, sub_result.find(sub_result[i]));
        std::string second = sub_result.substr(i);
        std::string r = first + input[0] + second;
        permutations(r, input.substr(1));
    }
}
std::vector<std::string> permutations_vector(std::string sub_result, std::string input)
{
    if(input.empty())    
    {
        std::vector<std::string> vec;
        vec.push_back(sub_result);
        return vec;
    }
    std::vector<std::string> ans;
    for(int i = 0; i <= sub_result.size(); i++)
    {
        std::string first = sub_result.substr(0, sub_result.find(sub_result[i]));
        std::string second = sub_result.substr(i);
        std::string r = first + input[0] + second;
        std::vector<std::string> sub_ans = permutations_vector(r, input.substr(1));
        for(auto element: sub_ans)
            ans.push_back(element);
    }
    return ans;
}
int permutations_count(std::string sub_result, std::string input)
{
    if(input.empty()) 
        return 1;
    int count = 0;
    for(int i = 0; i <= sub_result.size(); i++)
    {
        std::string first = sub_result.substr(0, sub_result.find(sub_result[i]));
        std::string second = sub_result.substr(i);
        std::string r = first + input[0] + second;
        count = count + permutations_count(r, input.substr(1));
    }
    return count;
}
