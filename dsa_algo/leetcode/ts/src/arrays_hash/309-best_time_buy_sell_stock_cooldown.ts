const dfs = (prices: number[], index: number, buying: number, res: number[][]): number => {
    if(index >= prices.length)
        return 0;
    if(res[index][buying] !== -1)
        return res[index][buying];
    const cooldown = dfs(prices, index + 1, buying, res);
    if(buying === 1)
    {
        const buy = dfs(prices, index + 1, 0, res) - prices[index];
        res[index][buying] = Math.max(buy, cooldown);
    }
     else if(buying === 0)
    {
        const sell = dfs(prices, index + 2, 1, res) + prices[index];
        res[index][buying] = Math.max(sell, cooldown);
    }
    return res[index][buying];
}
const maxProfit = (prices: number[]): number => {
    const prices_size: number = prices.length;
    const results_dp: number[][] = new Array(prices.length);
    for(let i = 0; i < prices_size; i++)
        results_dp[i] = new Array(2).fill(-1);

    return dfs(prices, 0, 1, results_dp);

};