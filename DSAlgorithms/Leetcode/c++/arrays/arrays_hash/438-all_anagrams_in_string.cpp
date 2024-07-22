class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::vector<int> result;
        if(p.size() > s.size())
            return result;
        std::unordered_map<int, int> p_hash;
        std::unordered_map<int, int> s_hash;
        for(int i = 0; i < p.size(); i++)
        {
            p_hash[p[i]]++; //add all p chars to hash
            s_hash[s[i]]++; //add p.size chars of s to hash
        }
            if(p_hash == s_hash)
                result.push_back(0);
        int left = 0;
        for(int right = p.size(); right < s.size(); right++)
        {
            s_hash[s[right]]++;
            s_hash[s[left]]--;
            if(s_hash[s[left]] == 0)
                s_hash.erase(s[left]);
            left ++;
            /*
            equal_hashes = true;
            for(auto [key, value]: p_hash)
            {
                if(value != s_hash[key])
                    {
                        equal_hashes = false;
                        break;
                    }
            }
            if(equal_hashes)
                result.push_back(left);
            */
            if(p_hash == s_hash)
                result.push_back(left);
        }
        return result;
    }

};