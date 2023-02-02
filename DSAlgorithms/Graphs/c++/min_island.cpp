#include <iostream>
#include <vector>
#include <unordered_map>

int min_island(std::vector<std::vector<char>>);
int explore_grid(std::vector<std::vector<char>>&, int, int, std::vector<std::vector<int>>&);
int main(int argc, const char** argv) 
{
    std::vector<std::vector<char>> grid 
    {
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'L', 'L', 'W'},
        {'L', 'W', 'W', 'L', 'L'},
        {'L', 'L', 'W', 'W', 'W'},
    };
    
    std::cout<<min_island(grid);
    std::cout<<'\n';
    return 0;
}
int min_island(std::vector<std::vector<char>> grid)
{
    int total_rows = grid.size();
    int total_cols = grid[0].size();
    int total_cells = total_rows * total_cols;
    std::vector<std::vector<int>> visited(total_rows, std::vector<int> (total_cols, 0));
    int min_size = 100000;
    for(int row = 0; row < visited.size(); row++)
    {
        for(int col = 0; col < visited[0].size(); col++)
        {
            //std::cout<<visited[row][col];
            int size = explore_grid(grid, row, col, visited);
            if(size > 0 && size < min_size)
                min_size = size;
        }
        //std::cout<<'\n';
    }
    return min_size;
}
int explore_grid(std::vector<std::vector<char>>& grid, int row, int col, std::vector<std::vector<int>>& visited)
{
    bool row_in_bounds = 0 <= row && row < grid.size();
    bool col_in_bounds = 0 <= col && col < grid[0].size();
    if(!row_in_bounds || !col_in_bounds)
        return 0;
    if(grid[row][col] == 'W')
        return 0;
    if(visited[row][col] == 1)
        return 0;
    visited[row][col] = 1;
    int size = 1;
    size += explore_grid(grid, row - 1, col, visited);
    size += explore_grid(grid, row + 1, col, visited);
    size += explore_grid(grid, row, col - 1, visited);
    size += explore_grid(grid, row, col + 1, visited);

    return size;
}