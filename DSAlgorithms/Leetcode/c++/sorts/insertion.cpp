#include<bits/stdc++.h>
void insertion(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    std::vector<int> arr = {6, 4, 3, 2, 0};
    insertion(arr);
    for(auto item: arr)
        std::cout<<item<<" ";
    std::cout<<'\n';
}
