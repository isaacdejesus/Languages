#include <iostream>
#include <vector>

int bsearch(std::vector<int>& nums, int target);
int main()
{
    std::vector<int> numbers_vector = {1, 3, 5, 7, 9, 11};
    std::cout<<bsearch(numbers_vector, 3)<<'\n';
    std::cout<<bsearch(numbers_vector, 6)<<'\n';
    return 0;
}
int bsearch(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(target == nums[mid])
            return mid;
        else if(target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
