const isValidSudoku = (board: string[][]): boolean =>{
    let size = 9;
    const row_: boolean[][] = new Array(size);
    const col_: boolean[][] = new Array(size);
    const sub_grid: boolean[][] = new Array(size);
    for(let i = 0; i < size; i++)
    {
        row_[i] = new Array(size);
        col_[i] = new Array(size);
        sub_grid[i] = new Array(size);
    }
    for(let i = 0; i < size; i++)
    {
        for(let j = 0; j < size; j++)
        {
            row_[i][j] = false;
            col_[i][j] = false;
            sub_grid[i][j] = false;
        }
    }
    for(let row = 0; row < size; row++)
    {
        for(let col = 0; col < size; col++)
        {
            if(board[row][col] === '.')
                continue;
            let index: number = parseInt(board[row][col]) - 1;
            let area: number = Math.floor(Math.floor((row/3)) * 3 + Math.floor((col/3)));
            if(row_[row][index] || col_[col][index] || sub_grid[area][index])
                return false;
            row_[row][index] = true;
            col_[col][index] = true;
            sub_grid[area][index] = true;
        }
    }
        return true;
};
