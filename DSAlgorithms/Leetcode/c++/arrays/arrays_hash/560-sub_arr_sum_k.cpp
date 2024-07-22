class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        int j = 0; 
        int count = 0;
        int n = size(nums);
        int sum = 0;
        std::unordered_map<int, int> hash;
        while(j < n)
        {
            sum += nums[j];
            if(sum == k)
                count++;
            if(hash.find(sum - k) != hash.end())
                count+= hash[sum - k];
            hash[sum]++;
            j++;
        }
        return count;
        
    }
};