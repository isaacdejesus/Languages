#include <iostream>
#include <unordered_map>
class Solution {
public:
    int maxProduct(std::string s) {
       int s_length = s.size();
       std::unordered_map<int, int> hash;
       for(int i = 1; i < 1 << s_length; i++) 
       {
           std::string subseq = "";
           for(int j = 0; j < s_length; j++)
           {
               if( i & (1 << j))
                    subseq += s[j];
           }
           std::string reversed = subseq;
           std::reverse(reversed.begin(), reversed.end());
           if(subseq == reversed)
                hash[i] = subseq.size();
       }
       int result = 0;
       for(auto item1: hash)
       {
           for(auto item2: hash)
           {
               if((item1.first & item2.first)== 0)
                    result = std::max(result, item1.second * item2.second );
           }
       }
        return result;
    }
};
