class Solution {
public:
    int minSwaps(string s) {
       int close = 0;
       int max_close = 0;
       for(int i = 0; i < s.size(); i++) 
       {
           if(s[i] == '[')
                close -= 1;
            else
                close += 1;
            max_close = std::max(close, max_close);
       }
       return (max_close + 1)/2;
    }
};