class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       std::unordered_set<char> a_set;
       int left = 0;
       int result = 0;
       for(int right = 0; right < s.size(); right++) 
       {
           std::unordered_set<char>::iterator char_iterator = a_set.find(s[right]);
           while(char_iterator != a_set.end())
           {
               a_set.erase(s[left]);
               left++;
              char_iterator = a_set.find(s[right]);
           }
           a_set.insert(s[right]);
           result = std::max(result, right - left + 1);
       }
       return result;
    }
};