const searchMatrix = (matrix: number[][], target: number): boolean =>{
    let rows_ = matrix.length;
    let cols_ = matrix[0].length;
    let top = 0;
    let bot = rows_ - 1;
    while(top <= bot)
    {
        let row = Math.floor(top + (bot - top) / 2);
        if(target > matrix[row][cols_ - 1])
            top = row + 1;
        else if(target < matrix[row][0])
            bot = row - 1;
        else 
            break;
    }
    if(top > bot)
        return false;
    let row = Math.floor(top + (bot - top) / 2);
    let left = 0;
    let right = cols_ -1;
    while(left <= right)
    {
        let mid = Math.floor(left + (right - left) / 2);
        if(target > matrix[row][mid])
            left = mid + 1;
        else if(target < matrix[row][mid])
            right = mid - 1;
        else 
            return true;
    }
    return false;

};
