#include<bits/stdc++.h>
std::vector<int> sorted_sq1(std::vector<int>& nums);
std::vector<int> sorted_sq2(std::vector<int>& nums);
int main()
{
    std::vector<int> v1 = {-4, -1, 0, 3, 10};
    std::vector<int> v2 = {-4, -1, 0, 3, 10};
    std::vector<int> res1 = sorted_sq1(v1);
    std::vector<int> res2 = sorted_sq1(v2);
    for(auto i: res1)
        std::cout<<i<<' ';
    std::cout<<'\n';
    for(auto i: res2)
        std::cout<<i<<' ';
    std::cout<<'\n';
    return 0;
}
std::vector<int> sorted_sq1(std::vector<int>& nums)
{
    size_t arr_length = nums.size();
    std::vector<int> ans(arr_length);
    for(size_t i = 0; i< arr_length; i++)
        ans[i] = nums[i] * nums[i];
    std::sort(ans.begin(), ans.end());
    return ans;
}
std::vector<int> sorted_sq2(std::vector<int>& nums)
{
    int arr_length = nums.size();
    std::vector<int> result(arr_length);
    int left = 0;
    int right = arr_length - 1;
    for(int i = arr_length - 1; i >= 0; i--)
    {
        int sq;
        if(abs(nums[left]) < abs (nums[right]))
        {
            sq = nums[right];
            right--;
        }
        else
        {
            sq = nums[left];
            left++;
        }
        result[i] = sq * sq;
    }
    return result;
}
