#include<bits/stdc++.h>
//striver implementation
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j)
    {
        while(arr[i] <= pivot && i <= high - 1)
            i++;
        while(arr[j] > pivot && j >= low + 1)
            j--;
        if(i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}

void qs(std::vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int pivot_index = partition(arr, low, high);
        qs(arr, low, pivot_index - 1);
        qs(arr, pivot_index + 1, high);
    }
}
std::vector<int> quicksort(std::vector<int> arr)
{
    qs(arr, 0, arr.size() - 1);
    return arr;
}
//kunal
void quick_sort(std::vector<int> &arr, int low, int high)
{
    if(low >= high)
        return;
    int start = low;
    int end = high;
    int mid = start + (end - start) / 2;
    int pivot = arr[mid];
    while(start <= end)
    {
        while(arr[start] < pivot)
            start++;
        while(arr[end] > pivot)
            end--;
        if(start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    quick_sort(arr, low, end);
    quick_sort(arr, start, high);
}

int main()
{
    std::vector<int>  v1 ={4, 2, 5, 9, 14, 2, 6, 0, 1, 3};
    std::vector<int>  v2 ={4, 2, 5, 9, 14, 2, 6, 0, 1, 3};
    std::vector<int> sorted = quicksort(v1);
    quick_sort(v2, 0, v2.size() - 1);

    for(auto item: sorted)
        std::cout<<item<<" ";
    std::cout<<'\n';
    for(auto item: v2)
        std::cout<<item<<" ";
    std::cout<<'\n';
}


