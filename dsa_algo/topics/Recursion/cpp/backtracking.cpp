#include <iostream>
#include <vector>

void path(std::string, int , int );
int count(int r, int c);
std::vector<std::string> path_results(std::string, int, int);
std::vector<std::string> path_results_diagonal(std::string, int, int);
void path_obstacles(std::string, std::vector<std::vector<bool>>, int, int);
void all_paths_backtracking(std::string sub_result, std::vector<std::vector<bool>> maze, int row, int col);
void all_paths_print(std::string sub_result, std::vector<std::vector<bool>>, int row, int col, std::vector<std::vector<int>>, int step);
int main()
{
    std::cout<<count(3,3)<<'\n';
    path("", 3,3);
    std::vector<std::string> path_res = path_results("", 3, 3);
    for(auto element: path_res)
        std::cout<<element<<' ';
    std::cout<<'\n';
    std::vector<std::string> diagonal_paths = path_results_diagonal("", 3, 3);
    for(auto element: diagonal_paths)
        std::cout<<element<<' ';
    std::cout<<'\n';
    std::vector<std::vector<bool>> grid = {{true, true, true},{true, false, true}, {true, true, true}};
    for(int row = 0; row < grid.size(); row++)
        for(int col = 0; col < grid[0].size(); col++)
            std::cout<<grid[row][col]<<' ';
    std::cout<<'\n';
    path_obstacles("", grid, 0, 0);
    std::cout<<'\n';
    std::vector<std::vector<bool>> grid2 = {{true, true, true},{true, true, true}, {true, true, true}};
    all_paths_backtracking("", grid2, 0, 0);
    std::cout<<'\n';
    std::vector<std::vector<int>> path_vector = {{0,0,0}, {0, 0, 0}, {0, 0, 0}};
    //path_vector.resize(grid2.size(), std::vector<int>(grid2[0].size()));
    all_paths_print("", grid2, 0, 0, path_vector, 0);
    return 0;
}

int count(int row, int col)
{
    if(row == 1 || col == 1)
        return 1;
    int left = count(row - 1, col);
    int right = count(row, col - 1);
    return left + right;
}
void path(std::string res, int row, int col)
{
    if(row == 1 && col == 1)
    {
        std::cout<<res<<'\n';
        return;
    }
    if(row > 1)
        path(res + 'D', row - 1, col);
    if(col > 1)
        path(res + 'R', row, col - 1);
}
std::vector<std::string> path_results(std::string sub_result, int row, int col)
{
    if(row == 1 && col == 1)
    {
        std::vector<std::string> vec;
        vec.push_back(sub_result);
        return vec;
    }
    std::vector<std::string> node_results;
    if(row > 1)
    {
        std::vector<std::string> left = path_results(sub_result + 'D', row - 1, col);
        for(auto element: left)
           node_results.push_back(element);
    }
    if(col > 1)
    {
        std::vector<std::string> right = path_results(sub_result + 'R', row, col - 1);
        for(auto element: right)
            node_results.push_back(element);
    }
    return node_results;

}
std::vector<std::string> path_results_diagonal(std::string sub_result, int row, int col)
{
    if(row == 1 && col == 1)
    {
        std::vector<std::string> vec;
        vec.push_back(sub_result);
        return vec;
    }
    std::vector<std::string> node_results;
    if(row > 1 && col > 1)
    {
        std::vector<std::string> diagonal_subtree = path_results_diagonal(sub_result + 'D', row - 1, col - 1);
        for(auto element: diagonal_subtree)
            node_results.push_back(element);
    }
    if(row > 1)
    {
        std::vector<std::string> row_subtree = path_results_diagonal(sub_result + 'V', row - 1, col);
        for(auto element: row_subtree)
            node_results.push_back(element);
    }
    if(col > 1)
    {
        std::vector<std::string> col_subtree = path_results_diagonal(sub_result + 'H', row, col - 1);
        for(auto element: col_subtree)
            node_results.push_back(element);
    }
    return node_results;
}
void path_obstacles(std::string sub_result, std::vector<std::vector<bool>> maze, int row, int col)
{
    if(row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        std::cout<<sub_result<<' ';
        return;
    }
    if(!maze[row][col])
        return;
    if(row < maze.size() - 1)
        path_obstacles(sub_result + 'D', maze, row + 1, col);
    if(col < maze[0].size() - 1)
        path_obstacles(sub_result + 'R', maze, row, col + 1);
}
void all_paths_backtracking(std::string sub_result, std::vector<std::vector<bool>> maze, int row, int col)
{
    if(row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        std::cout<<sub_result<<' ';
        return;
    }
    if(!maze[row][col])
        return;
    //consider this path
    maze[row][col] = false;
    
    if(row < maze.size() - 1)
        all_paths_backtracking(sub_result + 'D', maze, row + 1, col);
    
    if(col < maze[0].size() - 1)
        all_paths_backtracking(sub_result + 'R', maze, row, col + 1);

    if(row > 0)
        all_paths_backtracking(sub_result + 'U', maze, row - 1, col);
    if(col > 0)
        all_paths_backtracking(sub_result + 'L', maze, row, col - 1);

    //here function ends and recursion will begin to return
    //revert changes
    maze[row][col] = true;
}
void all_paths_print(std::string sub_result, std::vector<std::vector<bool>> maze, int row, int col, std::vector<std::vector<int>> path, int step)
{
    if(row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        path[row][col] = step;
        for(int r = 0; r < path.size(); r++)
        {
            for(int c = 0; c < path[0].size(); c++)
            {
                std::cout<<path[r][c]<<' ';
            }
                std::cout<<'\n';
        }
        std::cout<<sub_result<<'\n';
        std::cout<<'\n';
    }

    if(!maze[row][col])
        return;
    maze[row][col] = false;
    path[row][col] = step;

    if(row < maze.size() - 1)
        all_paths_print(sub_result + 'D', maze, row + 1, col, path, step + 1);
    if(col < maze[0].size() - 1)
        all_paths_print(sub_result + 'R', maze, row, col + 1, path, step + 1);
    if(row > 0)
        all_paths_print(sub_result + 'U', maze, row - 1, col, path, step + 1);
    if(col > 0)
        all_paths_print(sub_result + 'L', maze, row, col - 1, path, step + 1);
    maze[row][col] = true;
    path[row][col] = 0;
}
