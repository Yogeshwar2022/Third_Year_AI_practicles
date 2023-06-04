#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int dest;
    int weight;

    Edge(int dest, int weight)
        : dest(dest), weight(weight) {}
};

// Prim's algorithm for finding the minimum spanning tree
void primMST(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();

    vector<bool> visited(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);

    key[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minKey = INT_MAX, minVertex = -1;

        // Find the vertex with the minimum key value
        for (int v = 0; v < n; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minVertex = v;
            }
        }

        visited[minVertex] = true;

        // Update the key values of adjacent vertices
        for (const Edge& edge : graph[minVertex]) {
            int v = edge.dest;
            int weight = edge.weight;

            if (!visited[v] && weight < key[v]) {
                parent[v] = minVertex;
                key[v] = weight;
            }
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
    }
}

int main() {
    // Sample input
    int n = 5;  // Number of vertices
    int start = 0;  // Starting vertex

    vector<vector<Edge>> graph(n);

    // Add edges to the graph
    graph[0].push_back(Edge(1, 2));
    graph[1].push_back(Edge(0, 2));

    graph[1].push_back(Edge(2, 3));
    graph[2].push_back(Edge(1, 3));

    graph[0].push_back(Edge(3, 6));
    graph[3].push_back(Edge(0, 6));

    graph[1].push_back(Edge(3, 8));
    graph[3].push_back(Edge(1, 8));

    graph[1].push_back(Edge(4, 5));
    graph[4].push_back(Edge(1, 5));

    graph[2].push_back(Edge(4, 7));
    graph[4].push_back(Edge(2, 7));

    primMST(graph, start);

    return 0;
}
