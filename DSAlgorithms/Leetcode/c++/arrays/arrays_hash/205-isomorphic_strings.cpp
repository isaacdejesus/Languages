bool isIsomorphic(string s, string t) {
    std::unordered_map<char, char> st;
    std::unordered_map<char, char> ts;
    for( int i = 0; i < s.size(); i++)
    {
        char c1 = s[i];
        char c2 = t[i];
        if((st.count(c1) > 0 && st[c1] != c2)||(ts.count(c2) > 0 && ts[c2] != c1))
            return false;
        st[c1] = c2;
        ts[c2] = c1;
    }
    return true;
}