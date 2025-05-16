const make_squares = (arr:number[]) => {
    const n = arr.length;
    const squares = Array<number>(n).fill(0);
    let highest_sq_index = n - 1;
    let left = 0;
    let right = n - 1;
    while(left <= right)
    {
        let left_sq = arr[left] * arr[left];
        let right_sq = arr[right] * arr[right];
        if(left_sq > right_sq)
        {
            squares[highest_sq_index] = left_sq;
            left++;
        }
        else
        {
            squares[highest_sq_index] = right_sq;
            right--;
        }
        highest_sq_index -=1;
    }
    return squares;
}
console.log(`Squares: ${make_squares([-2, -1, 0, 2, 3])}`);
console.log(`Squares: ${make_squares([-3, -1, 0, 1, 2])}`);
