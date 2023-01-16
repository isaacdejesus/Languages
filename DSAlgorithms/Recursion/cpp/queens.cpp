#include <iostream>
#include <vector>

void display(std::vector<std::vector<bool>>);
bool isSafe(std::vector<std::vector<bool>>, int, int);
int queens(std::vector<std::vector<bool>> , int );
int main(int argc, const char** argv) 
{
    std::vector<std::vector<bool>> board = 
    {
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
    };
    //display(board);
    queens(board, 0);
    return 0;
}
void display(std::vector<std::vector<bool>> board)
{
    for(int row = 0; row < board.size(); row ++)
    {
        for(int col = 0; col < board[0].size(); col ++)
        {
            if(board[row][col])
                std::cout<<"Q ";
            else
                std::cout<<"X ";
        }
        std::cout<<'\n';
    }
}

int queens(std::vector<std::vector<bool>> board , int row)
{
    if(row == board.size())
    {
        display(board);
        std::cout<<'\n';
        return 1;
    }
    int count = 0;
    for(int col = 0; col < board[0].size(); col++)
    {
        if(isSafe(board, row, col))
        {
            board[row][col] = true;
            count += queens(board, row + 1);
            board[row][col] = false;
        }
    }
    return count;
}
bool isSafe(std::vector<std::vector<bool>> board, int row, int col)
{
    //check vertical row
    for(int r = 0; r < row; r++)
        if(board[r][col])
            return false;
    //check left diagonal
    int left_diagonal = std::min(row, col);
    for(int i = 1; i <= left_diagonal; i++)
        if(board[row - i][col - i])
            return false;
    //check right diagonal
    int s = board[0].size() - col - 1;
    int right_diagonal = std::min(row, s);
    for(int i = 1; i <= right_diagonal; i++)
        if(board[row - i][col+ i])
            return false;
    return true;
}
