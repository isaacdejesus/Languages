const gridGame = (grid: number[][]): number =>{
    const cols: number = grid[0].length;
    const prefix_row1: number[] = [];
    const prefix_row2: number[] = [];
    prefix_row1.push(grid[0][0]);
    prefix_row2.push(grid[1][0]);
    for(let i = 1; i < cols; i++)
    {
        let pre1: number = grid[0][i] + prefix_row1[i - 1];
        let pre2: number = grid[1][i] + prefix_row2[i - 1];
        prefix_row1.push(pre1);
        prefix_row2.push(pre2);
    }
    let result: number = Infinity;
    for(let i = 0; i < cols; i++)
    {
        let top_chunk: number = prefix_row1[cols -1] - prefix_row1[i];
        let bottom_chunk: number;
        if(i > 0)
            bottom_chunk = prefix_row2[i - 1];
        else
            bottom_chunk = 0;
        let second_bot_max: number = Math.max(top_chunk, bottom_chunk);
        result = Math.min(result, second_bot_max);
    }
    return result;

};