class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
       int ideas_size = ideas.size();
       std::unordered_map<std::string, int> word_hash;
       for(int i = 0; i < ideas_size; i++) 
            word_hash[ideas[i]]++;
        std::vector<std::vector<int>> dp(26, vector<int>(26,0));
        for(int i = 0; i < ideas_size; i++)
        {
            std::string word = ideas[i];
            char prefix = word[0];
            std::string suffix = word.substr(1);
            int prefix_index = (prefix-'a');
            for(int j = 0; j < 26; j++)
            {
                if(j == prefix_index)
                    continue;
                char new_char = ('a' + j);
                std::string new_word = new_char + suffix;
                if(word_hash.count(new_word) > 0)
                    continue;
                dp[prefix_index][j] +=1;
            }
        }
        long long ans = 0;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
            {
                if(i == j)
                    continue;
                if(dp[i][j] > 0)
                    ans += (dp[i][j] * dp[j][i]);
            }
    return ans;
    }
};
