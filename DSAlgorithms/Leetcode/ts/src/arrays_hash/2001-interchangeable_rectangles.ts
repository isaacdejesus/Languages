const interchangeableRectangles = (rectangles: number[][]): number =>{
    const hash = new Map<number, number>();
    let ratio: number = 0;
    let result: number = 0;
    for(let i = 0; i < rectangles.length; i++)
    {
        ratio = rectangles[i][0]/rectangles[i][1];
        if(hash.has(ratio))
        {
            const current_val = hash.get(ratio);
            hash.set(ratio, current_val + 1);
        }
        else
            hash.set(ratio, 1);
    }
    hash.forEach((value, key) => {
        if(value > 1)
            result += (value) * (value - 1) / 2;
    })
    return result;
};
