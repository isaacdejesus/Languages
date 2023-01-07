#include <iostream>
#include <vector>

std::vector<int> search(std::vector<std::vector<int>>, int);
int main()
{
    std::vector<std::vector<int>> matrix = {{10, 20, 30, 40}, {15, 25, 35, 45}, {28, 29, 37, 49}, {33, 34, 38, 50}};
    std::vector<int> result = search(matrix, 37);
    for(auto element: result)
        std::cout<<element<<'\n';
    std::cout<<'\n';
    return 0;
}
std::vector<int> search(std::vector<std::vector<int>> matrix, int target)
{
    int row  = 0;
    int col = matrix.size() - 1; 
    while(row < matrix.size() && col >= 0)
    {
        if(matrix[row][col] == target) 
            return {row, col};
        if(matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return {-1, -1};
}
