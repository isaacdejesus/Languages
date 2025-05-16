class Solution {
public:
    int strStr(string haystack, string needle) {
       if(needle == "") 
            return 0;
        int needle_size = needle.size();
        std::vector<int> lps(needle_size, 0);
        int prev_lps = 0;
        int i = 1;
        while( i < needle_size)
        {
            if(needle[i] == needle[prev_lps])
            {
                lps[i] = prev_lps + 1;
                prev_lps ++;
                i ++;
            }
            else if(prev_lps == 0)
            {
                    lps[i] = 0;
                    i ++;
            }
            else
                prev_lps = lps[prev_lps - 1];
        }
        i = 0;
        int j = 0;
        while(i < haystack.size())
        {
            if(haystack[i] == needle[j])
            {
                i ++;
                j ++;
            }
            else 
            {
            if(j == 0)
                {
                   i ++; 
                }
            else
                j = lps[j - 1];

            }
            if(j == needle_size)
                return i - needle_size;
        }
        return - 1;
    }
};