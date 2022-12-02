//sliding window
const maxP = (prices: number[]): number => { 
    let buy = 0;
    let sell = 1;
    let max = 0;
    while(sell < prices.length){
        if(prices[buy] < prices[sell]){
            let profit = prices[sell] - prices[buy];
            max = Math.max(max, profit);
        }
        else
            buy = sell;
        sell += 1;
    }
      return max;
}
