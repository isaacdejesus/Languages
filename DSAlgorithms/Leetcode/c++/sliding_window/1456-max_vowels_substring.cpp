class Solution {
public:
    int maxVowels(string s, int k) {
       std::unordered_set<char> vowels= {'a', 'e', 'i', 'o', 'u'};
       int left = 0;
       int count = 0;
       int result = 0;
       for(int right = 0; right < s.size(); right++)
       {
           std::unordered_set<char>::iterator find_char = vowels.find(s[right]);
           if(find_char != vowels.end())
                count++;
            if((right - left + 1) > k)
            {
                find_char = vowels.find(s[left]);
                if(find_char != vowels.end())
                    count--;
                left++;
            }
            result = std::max(result, count);
       }
       return result;
    }
};