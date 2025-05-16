class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       std::unordered_set<int> window;
       int left = 0;
       for(int right = 0; right < nums.size(); right++) 
       {
           if(right - left > k)
            {
                window.erase(nums[left]);
                left++;
            }
            std::unordered_set<int>::iterator set_iterator = window.find(nums[right]);
            if(set_iterator != window.end())
                return true;
            window.insert(nums[right]);
       }
       return false;
    }
};