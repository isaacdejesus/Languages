#include<bits/stdc++.h>
int remove_duplicates(std::vector<int> &arr, int n)
{
    int insert_index = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[insert_index] != arr[i])
        {
            arr[insert_index + 1] = arr[i];
            insert_index++;
        }
    }
    return insert_index + 1;
}
