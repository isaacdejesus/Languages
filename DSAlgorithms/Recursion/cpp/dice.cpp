#include <iostream>
#include <vector>
void dice(std::string, int);
void dice_face(std::string, int, int);
std::vector<std::string> dice_vector(std::string, int);
int main()
{
    dice("", 4);
    std::vector<std::string> dice_results = dice_vector("", 4);
    std::cout<<'\n';
    for(auto element: dice_results)
        std::cout<<element<<' ';
    std::cout<<'\n';
    dice_face("", 7, 8);
    return 0;
}
void dice(std::string sub_res, int target)
{
    if(target == 0)
    {
        std::cout<<sub_res<<' ';
        return;
    }
    for(int i = 1; i <= 6 && i <= target; i++)
        dice(sub_res + std::to_string(i), target - i);
}
std::vector<std::string> dice_vector(std::string sub_res, int target)
{
    if(target == 0)
    {
        std::vector<std::string> vec;
        vec.push_back(sub_res);
        return vec;
    }
    std::vector<std::string> results;
    for(int i = 1; i <= 6 && i <= target; i++)
    {
        std::vector<std::string> iter_res = dice_vector(sub_res + std::to_string(i), target - i);
        for(auto element: iter_res)
            results.push_back(element);
    }
    return results;
}
void dice_face(std::string sub_res, int target, int face)
{
    if(target == 0)
    {
        std::cout<<sub_res<<' ';
        return;
    }
    for(int i = 1; i <= face && i <= target; i++)
        dice_face(sub_res + std::to_string(i), target - i, face);
}
