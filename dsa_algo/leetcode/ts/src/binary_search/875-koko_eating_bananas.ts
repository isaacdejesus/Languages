const minEatingSpeed = (piles: number[], h: number): number =>{
    let left = 1;
    let right = 0;
    for(let i = 0; i < piles.length; i++)
        right = Math.max(piles[i], right);
    let result =  right;
    while(left <= right)
    {
        let k = Math.floor(left + (right - left) /2);
        let hours = 0;
        for(let i = 0; i < piles.length; i++)
            hours += Math.ceil(piles[i]/k);
            if(hours <= h)
            {
                result = Math.min(result, k);
                right = k - 1;
            }
            else
                left = k + 1;
    }
    return result;
};