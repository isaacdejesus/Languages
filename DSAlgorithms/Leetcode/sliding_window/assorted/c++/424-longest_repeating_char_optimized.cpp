class Solution {
public://optimized version
    int characterReplacement(string s, int k) {
       std::unordered_map<char, int> count_hash;
       int result = 0;
       int left = 0;
       int max_char = 0;
       for(int right = 0; right < s.size(); right++) 
       {
           if(count_hash.count(s[right]) > 0)
                count_hash[s[right]]++;
            else
                count_hash[s[right]]++;
            max_char = std::max(max_char, count_hash[s[right]]);

            //for(auto [key, value]: count_hash)
                //max_char = std::max(max_char, value);
            while(((right - left + 1) - max_char) > k)
            {
                if(count_hash.count(s[left]) > 0)
                    count_hash[s[left]]--;
                left++;
                //for(auto [key, value]: count_hash)
                    //max_char = std::max(max_char, value);
            }
            result = std::max(result, right - left + 1);
       }
       return result;
    }
};