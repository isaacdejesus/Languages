#include <iostream>
#include <vector>

static std::vector<int> search_indexes;
bool is_sorted(int[], int, int);
bool search(int[], int, int, int);
int find_index(int[], int, int, int);
void find_all_indexes(int arr[], int target, int index, int arr_length);
std::vector<int> find_all_indexes_return_vector(int arr[], int target, int index, std::vector<int>& vec, int arr_length);
static std::vector<int> find_all_indexes_return_vector2(int arr[], int target, int index, int arr_length);
int rotated_b_search(int arr[], int target, int s, int e);
int main()
{
    int sorted_arr[] = {1, 3, 5, 7};
    int not_sorted_arr[] = {1, 3, 2, 2, 5};
    int rotated_sorted_arr[] = {5, 6, 7, 8, 9, 1, 2, 4};
    std::cout<<is_sorted(sorted_arr, 0, 4)<<'\n';
    std::cout<<is_sorted(not_sorted_arr, 0, 4)<<'\n';
    std::cout<<search(not_sorted_arr, 2, 0, 4)<<'\n';
    find_all_indexes(not_sorted_arr, 2, 0, 5);
    for(auto element: search_indexes)
        std::cout<<element;
    std::cout<<'\n';
    std::vector<int> index_vector;
    find_all_indexes_return_vector(not_sorted_arr, 2, 0, index_vector, 5);
    for(auto element: index_vector)
        std::cout<<element;
    std::cout<<'\n';
    std::vector<int> res_vector = find_all_indexes_return_vector2(not_sorted_arr, 2, 0, 5);
    for(auto element: res_vector)
        std::cout<<element;
    std::cout<<'\n';
    std::cout<<rotated_b_search(rotated_sorted_arr, 1, 0, 7)<<'\n';

    return 0;
}
bool is_sorted(int arr[] , int index, int arr_length)
{
    if(index == arr_length - 1)
        return true;
    return arr[index] < arr[index + 1] && is_sorted(arr, index + 1, arr_length);
}

bool search(int arr[], int target, int index, int arr_length)
{
    if(index == arr_length)
        return false;
    return arr[index] == target || search(arr, target, index + 1, arr_length);
}
int find_index(int arr[], int target, int index, int arr_length)
{
   if(index == arr_length) 
        return -1;
   if(arr[index] == target)
        return index;
   else 
       return find_index(arr, target, index + 1, arr_length);
}

void find_all_indexes(int arr[], int target, int index, int arr_length)
{
    if(index == arr_length)
            return;
    if(arr[index] == target)
        search_indexes.push_back(index);
    find_all_indexes(arr, target, index + 1, arr_length);
}
//searches for all instances of target and returns a vector with indexes
std::vector<int> find_all_indexes_return_vector(int arr[], int target, int index, std::vector<int>& vec, int arr_length)
{
   if(index == arr_length) 
       return vec;
   if(arr[index] == target)
        vec.push_back(index);
   return find_all_indexes_return_vector(arr, target, index + 1, vec, arr_length);
}
//creating vector inside recursion not efficient. Best to use method above.
static std::vector<int> find_all_indexes_return_vector2(int arr[], int target, int index, int arr_length)
{
    std::vector<int> vec;
    if(index == arr_length)
        return vec;
    if(arr[index] == target)
        vec.push_back(index);
    //catch result returned from other calls
    std::vector<int> return_vector = find_all_indexes_return_vector2(arr, target, index + 1, arr_length);
    //append returned results to current vector
    if(!return_vector.empty())
    {
        for(auto element: return_vector)
            vec.push_back(element);
    }
    return vec;
}
int rotated_b_search(int arr[], int target, int s, int e)
{
    if(s > e)
        return -1;
    int m = s + (e - s) / 2;
    if(arr[m] == target)
        return m;
    if(arr[s] <= arr[m])
    {
        if(target >= arr[s] && target <= arr[m])
            return rotated_b_search(arr, target, s, m - 1);
        else 
            return rotated_b_search(arr, target, m + 1, e);
    }
    if(target >= arr[m] && target <= arr[e])
        return rotated_b_search(arr, target, m + 1, e);
    return rotated_b_search(arr, target, s, m - 1);
}
