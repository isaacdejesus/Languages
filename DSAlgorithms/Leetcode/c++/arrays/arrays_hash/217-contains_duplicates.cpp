class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++)
        {
            if(hash.count(nums[i]) > 0)
                return true;
            hash[nums[i]] = 1;
        }
        return false;
    }
};