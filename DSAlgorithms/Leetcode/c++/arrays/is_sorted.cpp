#include<bits/stdc++.h>
bool is_sorted(std::vector<int> &arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= arr[i - 1])
        {

        }
        else
            return false;
    }
    return true;
}
