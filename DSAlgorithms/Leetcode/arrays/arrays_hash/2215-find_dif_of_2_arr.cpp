class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1;
        std::unordered_set<int> set2;
        std::unordered_set<int> ans1;
        std::unordered_set<int> ans2;
        std::vector<int> res1;
        std::vector<int> res2;
        for(auto val : nums1)
            set1.insert(val);
        for(auto val: nums2)
            set2.insert(val);
        for(auto val: nums1)
        {
            std::unordered_set<int>::iterator it = set2.find(val);
            if(it == set2.end())
                ans1.insert(val);
        }
        for(auto val: nums2)
        {
            std::unordered_set<int>::iterator it = set1.find(val);
            if(it == set1.end())
                ans2.insert(val);
        }
        for(auto val: ans1)
           res1.push_back(val);
        for(auto val: ans2)
           res2.push_back(val);

        std::vector<std::vector<int>> res;
        res.push_back(res1);
        res.push_back(res2);

        return res;
    }
};