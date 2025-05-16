class NumMatrix {
    prefix_sum: number[][] = [];
    constructor(matrix: number[][]) {
        const rows: number = matrix.length;
        const cols: number = matrix[0].length;
        this.prefix_sum = matrix;
        for(let row = 0; row < rows; row++)
        {
            let prefix = 0;
            let above = 0;
            for(let col = 0; col < cols; col++)
            {
                prefix += matrix[row][col];
                if(row > 0)
                    above = this.prefix_sum[row -1][col];
                this.prefix_sum[row][col] = prefix + above;
            }
        }
    }

    sumRegion(row1: number, col1: number, row2: number, col2: number): number {
        let bottom_right = this.prefix_sum[row2][col2];
        let above = 0;
        let left = 0;
        let top_left = 0;
        if(row1 > 0)
            above = this.prefix_sum[row1- 1][col2];
        if(col1 > 0)
            left = this.prefix_sum[row2][col1 - 1];
        if(row1 > 0 && col1 > 0)
            top_left = this.prefix_sum[row1 - 1][col1 - 1];
        return bottom_right - above - left + top_left;

    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */