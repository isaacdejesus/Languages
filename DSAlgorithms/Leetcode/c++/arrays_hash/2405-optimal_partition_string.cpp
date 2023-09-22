class Solution {
public:
    int partitionString(string s) {
       int result = 1; 
       std::unordered_set<char> a_set;
       for(int i = 0; i < s.size(); i++)
       {
           std::unordered_set<char>::iterator it = a_set.find(s[i]);
           if(it != a_set.end())
            {
                result++;
                a_set.clear();
            }
            a_set.insert(s[i]);
       }
       return result;
    }
};