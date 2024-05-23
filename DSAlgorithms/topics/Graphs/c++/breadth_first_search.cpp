#include <iostream>
#include <queue>
#include <vector>

void bfs(std::vector<std::vector<int>>, int);
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
    bfs(matrix, 4);
    return 0;
}


void bfs(std::vector<std::vector<int>> matrix, int root)
{
    int current_node = root;
    std::queue<int> q;
    std::vector<int> visited (matrix.size(), 0);
    q.push(current_node);
    while(!q.empty())
    {
        current_node = q.front();
        q.pop();
        std::cout<<current_node<<' ';
        visited[current_node] = 1;
        for(int neighbor = 1; neighbor < matrix[0].size(); neighbor++)
        {
            if(matrix[current_node][neighbor] == 1 && visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}
