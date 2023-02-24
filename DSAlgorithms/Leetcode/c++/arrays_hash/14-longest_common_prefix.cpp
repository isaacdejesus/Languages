std::string longestCommonPrefix(vector<string>& strs) {
    std::string result = "";
    for(int i = 0; i < strs[0].size(); i++)
    {
        for(int s = 0; s < strs.size(); s++)
        {
            if( i == strs[s].size() || strs[s][i] != strs[0][i])
                return result;
        }
        result += strs[0][i];
    }
    return result;
}