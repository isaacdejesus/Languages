class Solution {
public:
        int dfs(vector<int>& prices, int index, int buying, std::vector<std::vector<int>>& res)
        {
            if(index >= prices.size() )
                return 0;    
            if(res[index][buying] != -1)
                return res[index][buying];
            int cooldown = dfs(prices, index + 1, buying, res);
            if(buying == 1)
            {
                int buy = dfs(prices, index + 1, 0, res) - prices[index];
                res[index][buying] = std::max(buy, cooldown);
            }
            else if(buying == 0)
            {
                int sell = dfs(prices, index + 2, 1, res) + prices[index];
                res[index][buying] = std::max(sell, cooldown);
            }
            return res[index][buying];
        }
    int maxProfit(vector<int>& prices) {
        int prices_size = prices.size();
        std::vector<std::vector<int>> results_dp(prices_size, vector<int>(2, -1));
        /* Does the same as above, init a 2d with prices_size rows and 
        2 cols filled with -1s
        std::vector<std::vector<int>> results_dp(prices_size);
        for(int row = 0; row < prices_size; row++)
        {
            results_dp[row] = std::vector<int> (2);
            for(int col = 0; col < results_dp[row].size(); col++)
                results_dp[row][col] = -1;
        }*/

        return dfs(prices, 0, 1, results_dp);
    }
};