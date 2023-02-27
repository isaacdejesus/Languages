vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    std::stack<int> a_stack;
    std::vector<int> result(nums1.size(), -1);
    std::unordered_map<int, int> hash;
    for(int i = 0; i < nums1.size(); i++)
        hash[nums1[i]] = i;
    for(int i = 0; i < nums2.size(); i++)
    {
        int current = nums2[i];
        while(!a_stack.empty() && current > a_stack.top())
        {
            int val = a_stack.top();
            a_stack.pop();
            int index = hash[val];
            result[index] = current;
        }
        if(hash.count(current) > 0)
            a_stack.push(current);
    }
    return result;
}