//Program returns returns vector containing second smallest and second largest numbers
#include<bits/stdc++.h>
int second_largest(std::vector<int> &arr, int n)
{
    int largest = arr[0];
    int second_largest = -1;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > second_largest)
            second_largest = arr[i];
    }
    return second_largest;
}

int second_smallest(std::vector<int> &arr, int n)
{
    int smallest = arr[0];
    int second_smallest = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < second_smallest)
            second_smallest = arr[i];
    }
    return second_smallest;
}
std::vector<int> second_order_elements(int n, std::vector<int> arr)
{
    int second_largest_val = second_largest(arr, n);
    int second_smallest_val = second_smallest(arr, n);
    return {second_largest_val, second_smallest_val};
}

int main()
{
    std::vector<int> arr = {3, 1, 0, 2, 7, 4, 5};
    std::vector<int> result = second_order_elements(7, arr);
    for(auto num: result)
        std::cout<<num<<" ";
    std::cout<<'\n';
}
