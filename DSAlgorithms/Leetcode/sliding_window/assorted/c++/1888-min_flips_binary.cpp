class Solution {
public:
    int minFlips(string s) {
       int window_size = s.size(); 
       s = s + s;
       std::string alt_string1 = "";
       std::string alt_string2 = "";
       for(int i = 0; i < s.size(); i++)
       {
           if(i % 2 == 0)
           {
                alt_string1 += '0';
                alt_string2 += '1';
           }
           else
            {
                alt_string1 += '1';
                alt_string2 += '0';
            }
       }
       int result = s.size();
       int diff1 = 0;
       int diff2 = 0;
       int left = 0;
       for(int right = 0; right < s.size(); right++)
       {
           if(s[right] != alt_string1[right])
                diff1++;
            if(s[right] != alt_string2[right])
                diff2++;

            if((right - left + 1) > window_size)
            {
                if(s[left] != alt_string1[left])
                    diff1--;
                if(s[left] != alt_string2[left])
                    diff2--;
                left++;
            }
            if((right - left + 1) == window_size)
                result = std::min({result, diff1, diff2});
       }
       return result;
    }
};