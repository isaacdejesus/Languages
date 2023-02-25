vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::vector<std::vector<std::string>> ans;
    std::unordered_map<std::string, std::vector<std::string>> hash;
    for(int i = 0; i < strs.size(); i++)    
    {
        std::string current_string = strs[i];
        std::sort(strs[i].begin(), strs[i].end());
        hash[strs[i]].push_back(current_string);
    }
    for(auto i: hash)
    {
        ans.push_back(i.second);
    }
    return ans;
    }