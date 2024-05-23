#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

void dfs(std::unordered_map<char, std::vector<char>>, char);
void dfs_rec(std::unordered_map<char, std::vector<char>>, char, std::unordered_map<char, bool>);
void dfs_iterative(std::unordered_map<char, std::vector<char>>, char);
int main()
{
    std::unordered_map<char, std::vector<char>> graph =
    {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E', 'F'}},
        {'C', {'G'}},
        {'D', {}},
        {'E', {}},
        {'F', {'H'}},
        {'G', {'I'}},
        {'H', {}},
        {'I', {}},
    };
    dfs(graph, 'A');
    std::cout<<'\n';
    dfs_iterative(graph, 'A');
    return 0;
}
void dfs(std::unordered_map<char, std::vector<char>> graph, char node)
{
    std::unordered_map<char, bool> visited;
    for(auto key: graph) 
        visited[key.first] = false;
    dfs_rec(graph, node, visited);

}
void dfs_rec(std::unordered_map<char, std::vector<char>> graph, char node, std::unordered_map<char, bool> visited)
{
    std::cout<<node<<' ';
    std::vector<char> neighbors = graph[node];
    visited[node] = true;
    for(auto neighbor: neighbors)
        if(!visited[neighbor])
            dfs_rec(graph, neighbor, visited);
}
void dfs_iterative(std::unordered_map<char, std::vector<char>> graph, char node)
{
    std::unordered_map<char, bool> visited;
    std::stack<char> a_stack;
    for(auto key: graph)
        visited[key.first] = false;

    a_stack.push(node);
    visited[node] = true;
    while(!a_stack.empty())
    {
        char current_node = a_stack.top();
        a_stack.pop();
        std::cout<<current_node<<' ';
        std::vector<char> neighbors = graph[current_node];
        for(auto neighbor: neighbors)
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                a_stack.push(neighbor);
            }
    }
}
