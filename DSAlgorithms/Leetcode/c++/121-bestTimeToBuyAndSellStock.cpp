#include<iostream>
#include<vector>

int maxProfit(std::vector<int>& prices);
int main()
{
    std::vector<int> a_vector = {7, 1, 5, 3, 6, 4};
    std::cout<<maxProfit(a_vector)<<'\n';
    return 0;
}
int maxProfit(std::vector<int>& prices)
{
    int buy = 0;
    int sell = 1;
    int max_profit = 0;
    int vector_size = prices.size();
    while(sell < vector_size)
    {
        if(prices[sell] > prices[buy])
        {
            int current_profit = prices[sell] - prices[buy];
            max_profit = std::max(max_profit, current_profit);
        }
        else if(prices[sell] < prices[buy])
            buy = sell;
        sell++;
    }
    return max_profit;
}