bool is_subsequence(string s, string t) 
{
    int first = 0;
    for(int i = 0; i < t.size(); i++) 
    {
        if(s[first] == t[i])
            first++;
    }
    if(first < s.size())
        return false;

    return true;
}


bool is_subsequence(string s, string t) 
{
    int i = 0;
    int j = 0;
    while(i < s.size() && j < t.size())
    {
        if(s[i] == t[j])
            i++;
        j++;
    }
    if(i == s.size())
        return true;
    return false;
}