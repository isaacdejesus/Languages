const minSwaps = (s: string): number =>{
    let closed: number = 0;
    let max_closed: number = 0;
    for(let i = 0; i < s.length; i++)
    {
        if(s[i] === "[")
            closed -= 1;
        else
            closed += 1;
        
        max_closed = Math.max(closed, max_closed);
    }
    return Math.floor((max_closed + 1)/2);

};