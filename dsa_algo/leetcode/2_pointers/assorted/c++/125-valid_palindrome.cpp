class Solution {
public:
    bool is_alpha_num(char c)
    {
        return ((int('A') <= int(c) && int(c) <= int('Z')) || 
                (int('a') <= int(c) && int(c) <= int('z')) || 
                (int('0') <= int(c) && int(c) <= int ('9')));
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while( left < right)
        {
            while(left < right && !is_alpha_num(s[left]))
                left += 1;
            while(right > left && !is_alpha_num(s[right]))
                right -= 1;
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            left += 1;
            right -= 1;
        }
        return true;
    }
};