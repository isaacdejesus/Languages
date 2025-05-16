const maxProfit = (prices: number[]):  number =>{
    let total_profit: number = 0;
    for(let day = 1; day < prices.length; day++)
        if(prices[day] > prices[day - 1])
            total_profit += prices[day] - prices[day - 1];
    
    return total_profit;
};