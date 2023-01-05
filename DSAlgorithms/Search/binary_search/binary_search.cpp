#include <iostream>
#include <vector>

int binary_search(std::vector<int>, int);  //works with ascending order only
int order_agnostic_binary_search(std::vector<int>, int);  //works with asc and desc orders
int ceiling(std::vector<int>, int);  //returns target or smallest number => target
int floor(std::vector<int>, int);  //returns target or largest number =< target
char smallest_letter(std::vector<char>, char);  //same as ceiling except with sorted letters
int main()
{
    std::vector<int> v = {2, 3, 5, 7, 9, 10};
    std::cout<<binary_search(v, 10)<<'\n';
    std::vector<int> v2 = {-18, -12, -4, 0, 2, 4, 15, 16, 18, 22, 45, 89};
    std::vector<int> v3 = {99, 88, 75, 22, 11, 10, 5, 2, -3};
    std::cout<<order_agnostic_binary_search(v2, 0)<<'\n';
    std::cout<<order_agnostic_binary_search(v3, 10)<<'\n';
    std::cout<<ceiling(v, 6)<<'\n';
    std::cout<<floor(v, 1)<<'\n';
    std::vector<char> chars_vector = { 'c', 'f', 'j'};
    std::cout<<smallest_letter(chars_vector, 'c')<<'\n';
    return 0;
}
int binary_search(std::vector<int> vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(vec[mid] == target)
            return mid;
        else if(target > vec[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int order_agnostic_binary_search(std::vector<int> vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    //determine if sorted ascending or descending
    bool isAsc = vec[left] < vec[right];
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(vec[mid] == target)
            return mid;
        if(isAsc)
        {
            if(target > vec[mid])
                left = mid + 1;
            else 
                right = mid - 1;
        }
        else
        {
            if(target > vec[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return -1;
}
int ceiling(std::vector<int> vec, int target)
{
    if(target > vec[vec.size() - 1]) //if at end of arr, there is no ceiling
        return -1;
    int left = 0;
    int right = vec.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(vec[mid] == target)
            return mid;
        else if(target > vec[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}
int floor(std::vector<int> vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(vec[mid] == target)
            return mid;
        else if(target > vec[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
char smallest_letter(std::vector<char> vec, char target)
{
    int left = 0;
    int right = vec.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(target < vec[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return vec[left % vec.size()];
}