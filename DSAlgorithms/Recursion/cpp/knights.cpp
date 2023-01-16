#include <iostream>
#include <vector>

void display(std::vector<std::vector<bool>>);
bool isSafe(std::vector<std::vector<bool>>, int, int);
void knight(std::vector<std::vector<bool>> , int , int , int );
bool isValid(std::vector<std::vector<bool>>, int, int);
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
    knight(board, 0, 0, 8);
    return 0;
}
void display(std::vector<std::vector<bool>> board)
{
    for(int row = 0; row < board.size(); row ++)
    {
        for(int col = 0; col < board[0].size(); col ++)
        {
            if(board[row][col])
                std::cout<<"K ";
            else
                std::cout<<"X ";
        }
        std::cout<<'\n';
    }
}

void knight(std::vector<std::vector<bool>> board , int row, int col, int knights)
{
    if(knights == 0)
    {
        display(board);
        std::cout<<'\n';
        return;
    }
    if(row == board.size() - 1 && col == board[0].size())
        return;
    if(col == board.size())
    {
        knight(board, row + 1, 0, knights);
        return;
    }
    if(isSafe(board, row, col))
    {
        board[row][col] = true;
        knight(board, row, col + 1, knights - 1);
        board[row][col] = false;
    }
    knight(board, row, col + 1, knights);
}
bool isSafe(std::vector<std::vector<bool>> board, int row, int col)
{
    if(isValid(board, row - 2, col - 1))
    {
        if(board[row - 2][col - 1])
            return false;
    }
    if(isValid(board, row - 1, col - 2))
    {
        if(board[row - 1][col - 2])
            return false;
    }
    if(isValid(board, row - 2, col + 1))
    {
        if(board[row - 2][col + 1])
            return false;
    }
    if(isValid(board, row - 1, col + 2))
    {
        if(board[row - 1][col + 2])
            return false;
    }
    return true;
}

bool isValid(std::vector<std::vector<bool>> board, int row, int col)
{
    if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size())
        return true;
    return false;
}
