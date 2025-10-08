#include<bits/stdc++.h>
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
int main()
{
    std::vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> arr2 = {2, 5, 6};
    merge(arr1, 3, arr2, 3);
    for(auto i: arr1)
        std::cout<<i<<' ';
    std::cout<<'\n';
    return 0;
}


void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int p1 = m - 1;
    int p2 = n - 1;
    for(int insert_loc = m + n - 1; insert_loc >= 0; insert_loc--)
    {
        if(p2 < 0)
            break;
        if(p1 >= 0 && nums1[p1] > nums2[p2])
            nums1[insert_loc] = nums1[p1--];
        else
            nums1[insert_loc] = nums2[p2--];
    }
};


