int lengthOfLastWord(string s) {
    int word_length = 0;
    for(int i = s.size() - 1; i >= 0; i--) 
    {
        if(s[i] != ' ')
            word_length++; 
        if(word_length > 0 && s[i] == ' ')
            break;
    }
    return word_length;
}