#include <iostream>
#include <vector>

int binary_search(std::vector<int>, int);  //works with ascending order only
int b_search(std::vector<int>, int, int, int);
int order_agnostic_binary_search(std::vector<int>, int);  //works with asc and desc orders
int order_agnostic_binary_search(std::vector<int>, int, int, int);  //works with asc and desc orders
int ceiling(std::vector<int>, int);  //returns target or smallest number => target
int floor(std::vector<int>, int);  //returns target or largest number =< target
char smallest_letter(std::vector<char>, char);  //same as ceiling except with sorted letters
std::vector<int> first_last_position(std::vector<int>, int);  //finds first and last position of target
int first_last_helper(std::vector<int> , int , bool );
int infinite_search(std::vector<int>, int, int, int);
int infinite_search_helper(std::vector<int>, int);
int mountain_search_peak(std::vector<int>);
int mountain_search(std::vector<int>, int);
int find_pivot(std::vector<int>);
int find_pivot_diplicates(std::vector<int>);
int rotated_search(std::vector<int>, int);
int count_rotations(std::vector<int>);
int split_arr(std::vector<int>, int);
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
    std::vector<int>  mountain_vec = {4, 5, 6, 7, 0, 1, 2};
    std::vector<int> single = {1};
    std::cout<<rotated_search(single, 0)<<'\n';
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
int b_search(std::vector<int> vec, int target, int start, int end)
{
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(target < vec[mid])
            end = mid - 1;
        else if(target > vec[mid])
            start = mid + 1;
        else
            return mid;
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
int order_agnostic_binary_search(std::vector<int> vec, int target, int start, int end)
{
    //determine if sorted ascending or descending
    bool isAsc = vec[start] < vec[end];
    while(start <= end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] == target)
            return mid;
        if(isAsc)
        {
            if(target > vec[mid])
                start = mid + 1;
            else 
                end = mid - 1;
        }
        else
        {
            if(target > vec[mid])
                start = mid - 1;
            else
                end = mid + 1;
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
std::vector<int> first_last_position(std::vector<int> vec, int target)
{
    std::vector<int> ans = { -1, -1 };
    ans[0]= first_last_helper(vec, target, true);
    ans[1]= first_last_helper(vec, target, false);
    return ans;
}
//searches for start/last index of given value
int first_last_helper(std::vector<int> vec, int target, bool find_start)
{
    int ans = -1;
    int left = 0;
    int right = vec.size() - 1; 
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(target < vec[mid])
            right = mid - 1;
        else if(target > vec[mid])
            left = mid + 1;
        else //found target
        {
            ans = mid;
            if(find_start) //if looking for start check left side
                right = mid - 1;
            else  //looking for last occurrence so check right side
                left = mid + 1;
        }
    }
    return ans;
}
int infinite_search(std::vector<int>vec, int target, int start, int end)
{
   while(start <= end) 
   {
        int mid = (start + end) / 2;
        if(target < vec[mid])
            end = mid - 1;
        else if(target > vec[mid])
            start = mid + 1;
        else
            return mid;
   }
   return -1;
}
int infinite_search_helper(std::vector<int>vec, int target)
{
    int start = 0;
    int end = 1;
    while(target> vec[end])
    {
        int newStart = end + 1;
        end = end + (end - start + 1) * 2;
        start = newStart;
    }
    return infinite_search(vec, target, start, end);
}
int mountain_search_peak(std::vector<int>vec )
{
    int start = 0;
    int end = vec.size() -1;
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(vec[mid] > vec[mid + 1])
            end = mid;
        else
            start =  mid + 1;
    }
    return start;
}
int mountain_search(std::vector<int>vec, int target)
{
    int peak = mountain_search_peak(vec);
    int search_ascending = order_agnostic_binary_search(vec, target, 0, peak);
    if(search_ascending != -1)
        return search_ascending;
    return  order_agnostic_binary_search(vec, target, peak + 1, vec.size() - 1);
}
int find_pivot(std::vector<int> vec)
{
    int start = 0;
    int end = vec.size() - 1;
    while(start <= end )
    {
        int mid = start  + (end - start) / 2;
        if( mid < end && vec[mid] > vec[mid + 1])
            return mid;
        if(mid > start && vec[mid] < vec[mid - 1])
            return mid - 1;
        if(vec[mid] <= vec[start])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
//used to search rotated arr with duplicates
int find_pivot_diplicates(std::vector<int> vec)
{
    int start = 0;
    int end = vec.size() - 1;
    while(start <= end )
    {
        int mid = start  + (end - start) / 2;
        if( mid < end && vec[mid] > vec[mid + 1])
            return mid;
        if(mid > start && vec[mid] < vec[mid - 1])
            return mid - 1;
        if(vec[mid] == vec[start] && vec[mid] == vec[end])
        {
            if(vec[start] > vec[start + 1])
                return start;
            start++;
            if(vec[end] < vec[end - 1])
                return end - 1;
            end--;
        }
        else if(vec[start] < vec[mid] || (vec[start] == vec[mid] && vec[mid] > vec[end]))
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int rotated_search(std::vector<int> vec, int target)
{
    int pivot = find_pivot(vec);
    if(pivot == -1)
        return b_search(vec, target, 0, vec.size() -1);
    if(pivot != -1 && vec[pivot] == target)
        return pivot;
    if(target >= vec[0])
        return b_search(vec, target, 0, pivot - 1);
    return b_search(vec, target, pivot + 1, vec.size() - 1);
}
int count_rotations(std::vector<int> vec)
{
    int pivot = find_pivot(vec);
    return pivot + 1;
}
int split_arr(std::vector<int>vec, int m)
{
    int start = 0;
    int end = 0;
    for(int i = 0; i < vec.size() - 1; i++)
    {
        start = std::max(start, vec[i]);
        end += vec[i];
    }
    while (start < end)
    {
        int mid = start + (end - start)  / 2;
        int sum = 0;
        int pieces = 1;
        for(auto element: vec)
        {
            if(sum + element > mid)
            {
                sum = element;
                pieces++;
            }
            else
                sum += element;
        }
        if(pieces > m)
            start = mid + 1;
        else end = mid;
    }
    return end;
}
