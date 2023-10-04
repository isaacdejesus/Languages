class Solution {
public:
    string minWindow(string s, string t) {
       if(t == "") 
            return "";
        
        std::unordered_map<char, int> window;
        std::unordered_map<char, int> t_hash;
        for(int i = 0; i < t.size(); i++)
            t_hash[t[i]]++;
        
        int have = 0;
        int need = t_hash.size();
        std::vector<int> result = {-1, -1};
        int result_length = std::numeric_limits<int>::max();
        int left = 0;
        for(int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;
            if(t_hash.count(c) > 0 && window[c] == t_hash[c])
                have++;
            while(have == need)
            {
               //update result 
               if((right - left + 1) < result_length)
               {
                   result[0] = left;
                   result[1] = right;
                   result_length = (right - left + 1);
               } 
               //pop left char 
               window[s[left]]--;
               if(t_hash.count(s[left]) > 0 && window[s[left]] < t_hash[s[left]])
                   have --;
                
                left++;
            }
        }
        if(result_length != std::numeric_limits<int>::max())
            return s.substr(result[0], result[1] - result[0] + 1);
        return "";
    }
};