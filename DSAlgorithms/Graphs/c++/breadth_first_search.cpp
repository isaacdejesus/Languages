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
    bfs(matrix, 1);
    return 0;
}


void bfs(std::vector<std::vector<int>> matrix, int root)
{
    int i = root;
    std::queue<int> q;
    std::vector<int> visited (matrix.size(), 0);
    std::cout<<i<<' ';
    visited[i] = 1;
    q.push(i);
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        for(int j = 1; j < matrix[0].size(); j++)
        {
            if(matrix[i][j] == 1 && visited[j] == 0)
            {
                std::cout<<j<<' ';
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}
