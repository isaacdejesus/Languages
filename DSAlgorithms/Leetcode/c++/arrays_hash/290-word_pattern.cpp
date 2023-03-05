class Solution {
public:
    bool wordPattern(string pattern, string s) {
       //get word count
       int word_count = 0;
       for(int i = 0; i < s.size(); i++) 
            if(s[i] == ' ')
                word_count++;
        word_count++;
        if(pattern.size() != word_count)
            return false;
        std::unordered_map<char, std::string> char_word;
        std::unordered_map<std::string, char> word_char;
        int j = 0;
        std::string current_word;
        for(int i = 0; i < pattern.size(); i++)
        {
            current_word = "";
            //get current word
            while(j < s.size())
            {
                if(s[j] == ' ')
                {
                   j++; 
                   break;
                }
                current_word+= s[j];
                j++;
            }
            if(char_word.count(pattern[i]) && char_word[pattern[i]] != current_word)
                return false;
            if(word_char.count(current_word) && word_char[current_word ] != pattern[i])
                return false;
            char_word[pattern[i]] = current_word;
            word_char[current_word] = pattern[i];
        }
        return true;
    }
};