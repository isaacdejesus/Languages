const generate = (numRows: number): number[][] =>{
    const triangle: number[][] = [];
    const first_row: number[] = [1];
    triangle.push(first_row);
    for(let i = 1; i < numRows; i++)
    {
        const previous_row: number[] = triangle[i - 1];
        const current_row:number[] = [1];
        for(let j = 1; j < i; j++)
            current_row.push(previous_row[j - 1] + previous_row[j]);
        current_row.push(1);
        triangle.push(current_row);
    }
    return triangle;
};
