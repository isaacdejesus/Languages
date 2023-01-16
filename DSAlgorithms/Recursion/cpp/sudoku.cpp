#include <iostream>
#include <vector>
#include <math.h>

bool isSafe(std::vector<std::vector<int>>&, int, int, int);
bool solve(std::vector<std::vector<int>>&);
void display(std::vector<std::vector<int>>);

int main()
{
    std::vector<std::vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };

    //display(board);
    if(solve(board))
        display(board);
    else
        std::cout<<"can't be solved"<<'\n';
    return 0;
}
bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int num)
{
    //check if number already exists in row
    for(int i = 0; i < board.size(); i++)
        if(board[row][col] == num)
            return false;
    //check if number already exists in col
    for(int r = 0; r < board.size(); r++)
    {
        std::cout<<"Checking col: "<<col<<" on row: "<<row<<'\n';
        if(board[r][col] == num)
            return false;
    }
    //check if number already in smaller box
    int sqroot = (int)(sqrt(board.size()));
    int row_start = row - row % sqroot;
    int col_start = col - col % sqroot;
    for(int r = row_start; r < row_start + sqroot; r++)
        for(int c = col_start; c < col_start + sqroot; c++)
            if(board[r][c] == num)
                return false;
    return true;
}
bool solve(std::vector<std::vector<int>>& board)
{
    int n = board.size();
    int row = -1;
    int col = -1;
    bool empty_left = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0)
            {
                row = i;
                col = j;
                empty_left = false;
                break;
            }
        }
        if(empty_left == false)
            break;
    }
    if(empty_left == true)
        return true;
    for(int number = 1; number <= 9; number++)
        if(isSafe(board, row, col, number))
        {
            board[row][col] = number;
            if(solve(board))
                return true;
            else
                board[row][col] = 0;
        }
    return false;
}
void display(std::vector<std::vector<int>> board)
{
    for(int row = 0; row < board.size(); row++)
    {
        for(int col = 0; col < board[0].size(); col++)
            std::cout<<board[row][col]<<' ';
        std::cout<<'\n';
    }
}
