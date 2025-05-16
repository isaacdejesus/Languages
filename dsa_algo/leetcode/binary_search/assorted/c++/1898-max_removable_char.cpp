class Solution {
public:
    bool is_subseq(std::string s, std::string subseq, std::unordered_set<int> a_set)
    {
        int i1 = 0;
        int i2 = 0;
        while(i1 < s.size() && i2 < subseq.size())
        {
            std::unordered_set<int>::iterator find_iterator = a_set.find(i1);
            if(find_iterator != a_set.end() || s[i1] != subseq[i2])
            {
                i1++;
                continue;
            }
            i1 ++;
            i2 ++;
        }
        return i2 == subseq.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int result = 0;
        int left = 0;
        int right = removable.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            std::unordered_set<int> a_set;
            for(int i = 0; i < mid + 1; i++)
                a_set.insert(removable[i]);
            if(is_subseq(s, p,a_set))
            {
                result = std::max(result, mid + 1);
                left = mid+ 1;
            }
            else
                right = mid - 1;
        }
        return result;
    }
};