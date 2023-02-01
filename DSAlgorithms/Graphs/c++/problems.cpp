#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

void dfs(std::unordered_map<char, std::vector<char>>, char);
void dfs_rec(std::unordered_map<char, std::vector<char>> , char, std::unordered_map<char, bool>);
bool dfs_has_path(std::unordered_map<char, std::vector<char>>, char, char);
bool dfs_has_path_rec(std::unordered_map<char, std::vector<char>> , char , char , std::unordered_map<char, bool>);
void bfs(std::unordered_map<char, std::vector<char>>, char);
bool bfs_has_path(std::unordered_map<char, std::vector<char>>, char, char);
//takes 2d arr of edges for undirected graph and returns adjecency list
std::unordered_map<char, std::vector<char>> adjecency_list_from_edges(std::vector<std::vector<char>>);
int dfs_components(std::unordered_map<int, std::vector<int>>);
bool dfs_rec_components(std::unordered_map<int, std::vector<int>> , int, std::unordered_map<int, bool>&);
int dfs_largest(std::unordered_map<int, std::vector<int>>);
int dfs_rec_largest(std::unordered_map<int, std::vector<int>> , int, std::unordered_map<int, bool>&);
int bfs_shortest(std::unordered_map<char, std::vector<char>>, char, char);
int main()
{
    std::unordered_map<char, std::vector<char>> graph = 
    {
        {'F', {'G', 'I'}},
        {'G', {'H'}},
        {'H', {}},
        {'I', {'G', 'K'}},
        {'J', {'I'}},
        {'K', {}},
    };
    std::unordered_map<char, std::vector<char>> graph_with_cycle = 
    {
        {'I', {'J', 'K'}},
        {'J', {'I', 'K'}},
        {'K', {'I', 'M', 'L', 'J'}},
        {'M', {'K'}},
        {'L', {'K'}},
        {'O', {'N'}},
        {'N', {'O'}},
    };
    std::vector<std::vector<char>> undirected_edges = 
    {
        {'W', 'X'},
        {'X', 'Y'},
        {'Z', 'Y'},
        {'Z', 'V'},
        {'W', 'V'},
    };
    std::vector<std::vector<char>> undirected_edges2= 
    {
        {'A', 'C'},
        {'A', 'B'},
        {'C', 'B'},
        {'C', 'D'},
        {'B', 'D'},
        {'E', 'D'},
        {'G', 'F'},
    };
    std::unordered_map<char, std::vector<char>> graph_from_edges = adjecency_list_from_edges(undirected_edges);
    std::unordered_map<char, std::vector<char>> graph_from_edges2 = adjecency_list_from_edges(undirected_edges);
    for(auto key: graph_from_edges)
    {
        std::cout<<key.first<<' ';
        for(auto element: key.second)
        {
            std::cout<<element<<' ';
        }
            std::cout<<'\n';
    }
    std::unordered_map<int, std::vector<int>> numbers_graph = 
    {
        {0, {8, 1, 5}},
        {1, {0}},
        {5, {0, 8}},
        {8, {0, 5}},
        {2, {3, 4}},
        {3, {2, 4}},
        {4, {3, 2}},
    };
    std::cout<<'\n';
    std::cout<<'\n';
    std::cout<<"Results for graph without cycles"<<'\n';
    std::cout<<dfs_has_path(graph, 'F', 'K')<<'\n';
    std::cout<<dfs_has_path(graph, 'J', 'F')<<'\n';
    std::cout<<bfs_has_path(graph, 'F', 'K')<<'\n';
    std::cout<<bfs_has_path(graph, 'J', 'F')<<'\n';
    std::cout<<"Results for graph with cycles"<<'\n';
    std::cout<<dfs_has_path(graph_with_cycle, 'I', 'L')<<'\n';
    std::cout<<dfs_has_path(graph_with_cycle, 'L', 'O')<<'\n';
    std::cout<<bfs_has_path(graph_with_cycle, 'I', 'L')<<'\n';
    std::cout<<bfs_has_path(graph_with_cycle, 'L', 'O')<<'\n';

    bfs(graph, 'F');
    std::cout<<'\n';
    //count segments of graph
    std::cout<<"Number of segments in graph"<<'\n';
    std::cout<<dfs_components(numbers_graph);
    std::cout<<'\n';
    //size of largest segment in segmented graph
    std::cout<<"Largest segment is: "<<'\n';
    std::cout<<dfs_largest(numbers_graph);
    std::cout<<'\n';
    //shortest path is
    std::cout<<"shortest path is"<<'\n';
    std::cout<<bfs_shortest(graph_from_edges, 'W', 'Z');
    std::cout<<'\n';
    //shortest path is
    std::cout<<"shortest path is"<<'\n';
    std::cout<<bfs_shortest(graph_from_edges2, 'B', 'G');
    std::cout<<'\n';
    return 0;
}
//original dfs
void dfs(std::unordered_map<char, std::vector<char>> graph, char source)
{
    std::unordered_map<char, bool> visited;
    for(auto key: graph)
        visited[key.first] = false;
    dfs_rec(graph, source, visited);
}
//original dfs
void dfs_rec(std::unordered_map<char, std::vector<char>> graph , char source, std::unordered_map<char, bool> visited)
{
    std::cout<<source<<' ';
    std::vector<char> neighbors = graph[source];
    visited[source] = true;
    for(auto neighbor: neighbors)
        if(!visited[neighbor])
            dfs_rec(graph, neighbor, visited);
}
bool dfs_has_path(std::unordered_map<char, std::vector<char>> graph, char source, char destination)
{
    std::unordered_map<char, bool> visited;
    for(auto key: graph)
        visited[key.first] = false;
    return dfs_has_path_rec(graph, source, destination, visited);
}
bool dfs_has_path_rec(std::unordered_map<char, std::vector<char>> graph, char source, char destination, std::unordered_map<char, bool> visited)
{
    if(source == destination)
        return true;
    std::vector<char> neighbors = graph[source];
    visited[source] = true;
    for(auto neighbor: neighbors)
        if(!visited[neighbor])
            if(dfs_has_path_rec(graph, neighbor, destination, visited) == true)
                return true;
    return false;
}
//original BFS
void bfs(std::unordered_map<char, std::vector<char>> graph, char source)
{
    std::unordered_map<char, bool> visited;
    std::queue<char> q;
    for(auto key: graph)
        visited[key.first] = false;
    q.push(source);
    while(!q.empty())
    {
        char current_node = q.front();
        q.pop();
        std::cout<<current_node<<' ';
        visited[source] = true;
        std::vector<char> neighbors = graph[current_node];
        for(auto neighbor: neighbors)
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
}
bool bfs_has_path(std::unordered_map<char, std::vector<char>> graph, char source, char destination)
{
    std::unordered_map<char, bool> visited;
    std::queue<char> q;
    for(auto key: graph)
        visited[key.first] = false;
    q.push(source);
    while(!q.empty())
    {
        char current_node = q.front();
        q.pop();
        visited[source] = true;
        if(current_node == destination)
            return true;
        std::vector<char> neighbors = graph[current_node];
        for(auto neighbor: neighbors)
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
    }
    return false;
}
std::unordered_map<char, std::vector<char>> adjecency_list_from_edges(std::vector<std::vector<char>> edges)
{
    std::unordered_map<char, std::vector<char>> graph; 
    for(int i = 0; i < edges.size(); i++)
    {
        char first = edges[i][0];
        char second = edges[i][1];
        if(graph.count(first) == 0)
            graph[first] = {};
        if(graph.count(second) == 0)
            graph[second] = {};
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
    return graph;
}
int dfs_components(std::unordered_map<int, std::vector<int>> graph)
{
    std::unordered_map<int, bool> visited;
    int count = 0;
    for(auto key: graph)
        visited[key.first] = false;
    for(auto key: graph)
        if(dfs_rec_components(graph, key.first, visited) == true)
            count+= 1;
    return count;
}
bool dfs_rec_components(std::unordered_map<int, std::vector<int>> graph , int source, std::unordered_map<int, bool>& visited)
{
    if(visited[source] == true)
        return false;
    std::vector<int> neighbors = graph[source];
    visited[source] = true;
    for(auto neighbor: neighbors)
        if(!visited[neighbor])
            dfs_rec_components(graph, neighbor, visited);
    return true;
}
int dfs_largest(std::unordered_map<int, std::vector<int>> graph)
{
    std::unordered_map<int, bool> visited;
    int largest = 0;
    for(auto key: graph)
        visited[key.first] = false;
    for(auto key: graph)
    {
        int size = dfs_rec_largest(graph, key.first, visited);
        if(size > largest)
            largest = size;
    }
    return largest;
}
int dfs_rec_largest(std::unordered_map<int, std::vector<int>> graph , int source, std::unordered_map<int, bool>& visited)
{
    if(visited[source] == true)
        return 0;
    std::vector<int> neighbors = graph[source];
    visited[source] = true;
    int size = 1;
    for(auto neighbor: neighbors)
        if(!visited[neighbor])
            size += dfs_rec_largest(graph, neighbor, visited);
    return size;
}
int bfs_shortest(std::unordered_map<char, std::vector<char>> graph, char source, char destination)
{
    std::unordered_map<char, bool> visited;
    std::queue<std::unordered_map<char, int>> q;
    for(auto key: graph)
        visited[key.first] = false;
    std::unordered_map<char, int> node;
    node[source] = 0;
    q.push(node);
    std::unordered_map<char, int>::iterator it;
    while(!q.empty())
    {
        std::unordered_map<char, int>  current_node = q.front();
        q.pop();
        node.clear();
        visited[source] = true;
        it = current_node.begin();
        if(it->first == destination)
            return it->second;
        std::vector<char> neighbors = graph[it->first];
        for(auto neighbor: neighbors)
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                node[neighbor] = it->second + 1;
                q.push(node);
                node.clear();
            }
    }
    return -1;
}
