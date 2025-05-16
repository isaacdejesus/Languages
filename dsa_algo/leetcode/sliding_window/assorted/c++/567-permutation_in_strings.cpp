class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s1.size() > s2.size()) 
            return false;
        std::vector<int> s1_count(26, 0);
        std::vector<int> s2_count(26, 0);
        for(int i = 0; i < s1.size(); i++)
        {
            s1_count[int(s1[i]) - int('a')] += 1;
            s2_count[int(s2[i]) - int('a')] += 1;
        }
        int matches = 0;
        for(int i = 0; i < 26; i++)
        {
            if(s1_count[i] == s2_count[i])
                matches++;
        }
        int left = 0;
        for(int right = s1.size(); right < s2.size(); right++ )
        {
            if(matches == 26)
                return true;
            int index = int(s2[right]) - int('a');
            s2_count[index]++;
            if(s1_count[index] == s2_count[index])
                matches++;
            else if(s1_count[index] + 1 == s2_count[index])
                matches--;

            index = int(s2[left]) - int('a');
            s2_count[index]--;
            if(s1_count[index] == s2_count[index])
                matches++;
            else if(s1_count[index] - 1 == s2_count[index])
                matches--;
            left++;
        }
        return matches == 26;
    }
};