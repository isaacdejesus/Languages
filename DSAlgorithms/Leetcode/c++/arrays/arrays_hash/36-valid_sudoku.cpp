class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9;
        bool row_[size][size] = {false};
        bool col_[size][size] = {false};
        bool sub[size][size] = {false};
        for(int row = 0; row < size; row++)
            for(int col = 0; col < size; col++)
            {
                if(board[row][col] == '.')
                    continue;
                int index = board[row][col] - '0' - 1;  //cast char to int
                int area = (row/3) * 3 + (col/3);
                if(row_[row][index] || col_[col][index] || sub[area][index])
                    return false;
                row_[row][index] = true;
                col_[col][index] = true;
                sub[area][index] = true;
            }
        return true;
    }

};