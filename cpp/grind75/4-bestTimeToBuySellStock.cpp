#include<bits/stdc++.h>
int maxProfit(std::vector<int>& prices)
{
    int buy = 0;
    int sell = 1;
    int maxP = 0;
    while( sell < prices.size())
    {
        if(prices[buy] < prices[sell])
        {
            int profit = prices[sell] - prices[buy];
            maxP = std::max(maxP, profit);
        }
        else
            buy = sell;
        sell += 1;
    }
    return maxP;
}
int main ()
{
    return 0;
}
