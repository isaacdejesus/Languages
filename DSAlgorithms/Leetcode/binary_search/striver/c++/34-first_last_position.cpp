class Solution {
public:
   int first_last_helper(std::vector<int> vec, int target, bool find_start)
{
    int ans = -1;
    int left = 0;
    int right = vec.size() - 1; 
    while(left <= right)
    {
        int mid = left + (right - left) /2;
        if(target < vec[mid])
            right = mid - 1;
        else if(target > vec[mid])
            left = mid + 1;
        else //found target
        {
            ans = mid;
            if(find_start) //if looking for start check left side
                right = mid - 1;
            else  //looking for last occurrence so check right side
                left = mid + 1;
        }
    }
    return ans;
}
 
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> ans = { -1, -1 };
        ans[0]= first_last_helper(nums, target, true);
        ans[1]= first_last_helper(nums, target, false);
        return ans;
    }
};