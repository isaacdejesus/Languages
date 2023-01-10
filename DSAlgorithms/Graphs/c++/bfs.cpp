#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

void bfs(std::unordered_map<char, std::vector<char>>, char);
int main()
{
    std::unordered_map<char, std::vector<char>> graph =
    {
        {'A', {'C', 'B'}},
        {'B', {'D', 'E', 'F'}},
        {'C', {'G'}},
        {'D', {}},
        {'E', {}},
        {'F', {'H'}},
        {'G', {'I'}},
        {'H', {}},
        {'I', {}},
    };
    bfs(graph, 'A');
    return 0;
}
void bfs(std::unordered_map<char, std::vector<char>> graph, char node)
{
    std::unordered_map<char, bool> visited;
    std::queue<char> q;
    for(auto key: graph) 
        visited[key.first] = false;
    q.push(node);
    while(!q.empty())
    {
        char current_node = q.front();
        q.pop();
        visited[node] = true;
        std::cout<<current_node<<' ';
        std::vector<char> neighbors = graph[current_node];
        for(auto neighbor: neighbors)
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
}
