class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size())
            return false;
       std::unordered_set<std::string> a_set; 
       for(int i = 0; i < (s.size() - k + 1); i++)
            a_set.insert(s.substr(i, k));

       std::cout<<a_set.size()<<" "<<2 << k; 
        return (a_set.size() == (1 << k));
    }
};
