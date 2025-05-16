class Solution {
public:
    int find_pivot(std::vector<int> vec)
    {
    int start = 0;
    int end = vec.size() - 1;
    while(start <= end )
    {
        int mid = start  + (end - start) / 2;
        if( mid < end && vec[mid] > vec[mid + 1])
            return mid;
        if(mid > start && vec[mid] < vec[mid - 1])
            return mid - 1;
        if(vec[mid] <= vec[start])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
    }
int b_search(std::vector<int> vec, int target, int start, int end)
{
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(target < vec[mid])
            end = mid - 1;
        else if(target > vec[mid])
            start = mid + 1;
        else
            return mid;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
    int pivot = find_pivot(nums);
    std::cout<<pivot;
    if(pivot == -1)
        return b_search(nums, target, 0, nums.size() -1);
    if(pivot != -1 && nums[pivot] == target)
        return pivot;
    if(target >= nums[0])
        return b_search(nums, target, 0, pivot - 1);
    return b_search(nums, target, pivot + 1, nums.size() - 1);
    }
};