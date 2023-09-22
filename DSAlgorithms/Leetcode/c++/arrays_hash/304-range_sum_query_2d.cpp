class NumMatrix {
public:
    std::vector<std::vector<int>> prefix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
       int rows = matrix.size(); 
       int cols = matrix[0].size();
       prefix_sum = matrix;

       //calc prefixsums
       for(int row = 0; row < rows; row++)
       {
           int prefix = 0;
           int above = 0;
           for(int col = 0; col < cols; col++)
           {
               prefix += matrix[row][col];
               if(row > 0)
                    above = prefix_sum[row - 1][col];
                prefix_sum[row][col] = prefix + above;
           }
       }
       for(int i = 0; i < rows; i++)
       {
           for(int j = 0; j < cols; j++)
                {
                    std::cout<<prefix_sum[i][j]<<" ";
                }
       std::cout<<'\n';
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottom_right = prefix_sum[row2][col2];
        int above = 0;
        int left = 0;
        int top_left = 0;
        if(row1 > 0)
             above = prefix_sum[row1 - 1][col2];
        if(col1 > 0)
            left = prefix_sum[row2][col1 - 1];
        if(row1 > 0 && col1 > 0)
            top_left = prefix_sum[row1 - 1][col1 - 1];

        return bottom_right - above - left + top_left;

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */