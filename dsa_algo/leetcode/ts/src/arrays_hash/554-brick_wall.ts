const leastBricks = (wall: number[][]): number =>{
    const hash = new Map<number, number>();
    hash.set(0, 0);
    for(let row = 0; row < wall.length; row++)
    {
        let current_index = 0;
        for(let col = 0; col < wall[row].length - 1; col++)
        {
            current_index+=wall[row][col];
            if(hash.has(current_index))
            {
                let current_val = hash.get(current_index);
                hash.set(current_index, current_val + 1);
            }
            else
                hash.set(current_index, 1);
        }
    }
        let max = 0;
        hash.forEach((value, key) => {
            max = Math.max(max, value);
            console.log(value);
        })
        return wall.length - max;
};
