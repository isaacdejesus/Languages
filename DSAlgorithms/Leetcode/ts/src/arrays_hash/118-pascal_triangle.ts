const generate = (numRows: number): number[][] =>{
    const triangle: number[][] = [];
    if(numRows === 0)
        return triangle;
    const first_row: number[] = [];
    first_row.push(1);
    triangle.push(first_row);
    for(let i = 1; i < numRows; i++)
    {
        const prev_row: number[] = triangle[i - 1];
        const current_row: number[] = [];
        current_row.push(1);
        for(let j = 1; j < i; j++)
            current_row.push(prev_row[j - 1] + prev_row[j])
        current_row.push(1);
        triangle.push(current_row);
    }
    return triangle;
};
