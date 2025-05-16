#include<bits/stdc++.h>
void selection(std::vector<int>& arr)
{
    for(int i = 0; i <= arr.size() - 2; i++)
    {
        int min = i;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[j] < arr[min]) 
                min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    std::vector<int> arr = {9, 3, 2, 4, 6, 1};
    selection(arr);
    for(auto item: arr)
        std::cout<<item<<" ";
    std::cout<<'\n';
}

