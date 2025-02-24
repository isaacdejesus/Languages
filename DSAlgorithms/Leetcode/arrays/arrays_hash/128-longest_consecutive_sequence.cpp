class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       std::unordered_set<int> a_set(nums.begin(), nums.end());
       int longest = 0;
       for(auto &num: a_set)
       {
           if(!a_set.count(num - 1))
           {
               int length = 1;
               while(a_set.count(num + length))
                ++length;
                longest = std::max(longest, length);
           }
       }
       return longest;
    }
};