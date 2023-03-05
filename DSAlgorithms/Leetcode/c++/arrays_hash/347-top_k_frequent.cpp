class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int arr_size = nums.size();
        std::unordered_map<int, int> hash;
        for(int i = 0; i < arr_size; i++)
            hash[nums[i]]++;
        
        std::vector<std::vector<int>> buckets(arr_size + 1);
        for(auto it = hash.begin(); it!= hash.end(); it++)
            buckets[it->second].push_back(it->first);
        std::vector<int> result;
        for(int i = arr_size; i >= 0; i--)
        {
            if(result.size() >= k)
                break;
            if(!buckets[i].empty())
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }
        return result;
    }
};