#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>, int);
std::vector<int> visited (7, 0);
int main()
{
    std::vector<std::vector<int>> matrix 
        {{0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    dfs(matrix, 4);
    return 0;
}


void dfs(std::vector<std::vector<int>> matrix, int root)
{
    if(visited[root] == 0)
    {
        std::cout<<root<<' ';
        visited[root] = 1;
        for(int neighbor = 1; neighbor < matrix[0].size(); neighbor++)
            if(matrix[root][neighbor] == 1 && visited[neighbor] == 0)
                dfs(matrix, neighbor);
    }

}


