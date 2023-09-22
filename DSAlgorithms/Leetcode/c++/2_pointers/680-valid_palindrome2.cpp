class Solution {
public:
    bool validPalindrome(string s) {
       int left = 0;
       int right = s.size() - 1;
       while(left < right) 
       {
           if(s[left] != s[right])
            {
                std::string skip_left = s.substr(left + 1, right - left); //substring without left char
                std::string skip_right = s.substr(left, right - left); //substring without right char   
                std::string reversed_left = skip_left;
                std::string reversed_right = skip_right;
                reverse(reversed_left.begin(), reversed_left.end());
                reverse(reversed_right.begin(), reversed_right.end());
                return (skip_left == reversed_left || skip_right == reversed_right);
            }
            left ++;
            right --;
       }
       return true;
    }
};