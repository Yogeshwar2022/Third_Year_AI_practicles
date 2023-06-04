#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int index;
    int distance;
};

// Comparison function for the priority queue
struct Compare {
    bool operator()(const Vertex& v1, const Vertex& v2) {
        return v1.distance > v2.distance;
    }
};

// Dijkstra's algorithm for single-source shortest path
void dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INF);  // Initialize distances to infinity
    vector<bool> visited(n, false);  // Mark all vertices as unvisited

    distance[source] = 0;  // Distance of source vertex is 0

    priority_queue<Vertex, vector<Vertex>, Compare> pq;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().index;
        int dist = pq.top().distance;
        pq.pop();

        // If the vertex is already visited, continue to the next iteration
        if (visited[u])
            continue;

        visited[u] = true;

        // Update the distance of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist != INF && dist + graph[u][v] < distance[v]) {
                distance[v] = dist + graph[u][v];
                pq.push({v, distance[v]});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF)
            cout << "Not reachable";
        else
            cout << distance[i];
        cout << endl;
    }
}

int main() {
    // Sample input
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int source = 0;  // Source vertex

    dijkstra(graph, source);

    return 0;
}
