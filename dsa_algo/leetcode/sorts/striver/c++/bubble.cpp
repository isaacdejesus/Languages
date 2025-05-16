#include<bits/stdc++.h>
void bubble(std::vector<int>& arr)
{
    for(int i = arr.size() - 1; i >= 1; i-- )
    {
        for(int j = 0; j < i ; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    std::vector<int> arr ={4, 2, 6, 3, 9, 0};
    bubble(arr);
    for(auto item: arr)
        std::cout<<item<<" ";
    std::cout<<'\n';
}
