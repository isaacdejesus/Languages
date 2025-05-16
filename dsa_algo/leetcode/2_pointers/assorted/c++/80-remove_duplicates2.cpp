class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insert_loc = 0;
        int right = 0;
        while(right < nums.size())
        {
            int current_duplicate_count = 1;
            while((right + 1< nums.size()) && nums[right] == nums[right + 1])
            {
                right++;
                current_duplicate_count++;
            }
            int duplicate_count = std::min(2, current_duplicate_count);
            for(int i = 0; i < duplicate_count; i++)
            {
                nums[insert_loc] = nums[right];
                insert_loc++;
            }
            right++;
        }
        return insert_loc;
    }
};