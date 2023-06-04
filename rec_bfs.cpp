#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS recursively
void bfs(vector<vector<int>>& graph, vector<bool>& visited, queue<int>& q)
{
    if (q.empty()) {
        return;
    }

    int node = q.front();
    q.pop();
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            q.push(neighbor);
            visited[neighbor] = true;
        }
    }

    bfs(graph, visited, q);
}

// Function to initialize and call BFS
void recursiveBFS(vector<vector<int>>& graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    bfs(graph, visited, q);
}

int main()
{
    

    int numVertices = 6; // Number of vertices in the graph

    // Create an adjacency list representation of the graph
    vector<vector<int>> graph(numVertices);

    // Add edges to the graph
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3, 4};
    graph[2] = {0, 1, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {1, 2, 3, 5};
    graph[5] = {3, 4};

    int startVertex = 0; // Starting vertex for BFS traversal

    cout << "BFS traversal starting from vertex " << startVertex << ": ";

    recursiveBFS(graph, startVertex );
// int n, m;
    // cout << "Enter the number of nodes: ";
    // cin >> n;
    // cout << "Enter the number of edges: ";
    // cin >> m;

    // vector<vector<int>> graph(n);

    // cout << "Enter the edges (u v):\n";
    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u);
    // }

    // int startNode;
    // cout << "Enter the starting node: ";
    // cin >> startNode;

    // cout << "BFS traversal starting from node " << startNode << ": ";
    // recursiveBFS(graph, startNode);
    return 0;
}
