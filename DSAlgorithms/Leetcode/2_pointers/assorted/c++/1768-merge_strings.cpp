class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int i = 0;
       int j = 0; 
        std::string result;
        while(i < word1.size() && j < word2.size())
        {
            result.push_back(word1[i]);
            result.push_back(word2[j]);
            i++;
            j++;
        }
        result.append(word1.substr(i));
        result.append(word2.substr(j));
        return result;
    }
};