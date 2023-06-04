#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Function to perform recursive DFS traversal
void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true;  // Mark the current node as visited
    cout << node << " ";   // Process the current node (in this case, we print it)

    // Traverse all adjacent nodes of the current node
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);  // Recursively call DFS on the unvisited neighbor
        }
    }
}

// Function to initialize DFS traversal
void dfsTraversal(int startNode, vector<vector<int>>& graph) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);  // Create a visited array to track visited nodes

    dfs(startNode, visited, graph);  // Call the recursive DFS function
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;

        // Add edges to the adjacency list representation of the graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "DFS traversal starting from node " << startNode << ": ";
    dfsTraversal(startNode, graph);
//     int numVertices = 6; // Number of vertices in the graph

//     // Create an adjacency list representation of the graph
//     vector<vector<int>> graph(numVertices);

//     // Add edges to the graph
//     graph[0] = {1, 2};
//     graph[1] = {0, 2, 3, 4};
//     graph[2] = {0, 1, 4};
//     graph[3] = {1, 4, 5};
//     graph[4] = {1, 2, 3, 5};
//     graph[5] = {3, 4};

//     int startVertex = 0; // Starting vertex for BFS traversal

//     cout << "BFS traversal starting from vertex " << startVertex << ": ";
// dfsTraversal(startVertex, graph);

    return 0;
}
