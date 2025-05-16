const successfulPairs = (spells: number[], potions: number[], success: number): number[] =>{
    potions.sort((a, b) => a - b);
    const result : number[] = [];
    for(let i = 0; i < spells.length; i++)
    {
        let left = 0;
        let right = potions.length - 1;
        let index = potions.length; 
        while(left <= right)
        {
            let mid = Math.floor(left + (right - left) /2);
            if(spells[i] * potions[mid] >= success)
            {
                right = mid - 1;
                index = mid;
            }
            else 
                left = mid + 1;
        }
        result.push(potions.length - index);
    }
    return result;
};