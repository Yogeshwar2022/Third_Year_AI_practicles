#include <iostream>
#include <vector>

using namespace std;

// Function to check if it is safe to color the vertex with the given color
bool isSafe(int vertex, int color, const vector<vector<int>>& graph, const vector<int>& colors) {
    for (int i = 0; i < graph[vertex].size(); i++) {
        int neighbor = graph[vertex][i];
        if (colors[neighbor] == color) {
            return false;
        }
    }
    return true;
}

// Recursive function to assign colors to the vertices of the graph
bool graphColoringUtil(int vertex, int numColors, vector<vector<int>>& graph, vector<int>& colors) {
    if (vertex == graph.size()) {
        return true;  // All vertices have been colored
    }

    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertex, color, graph, colors)) {
            colors[vertex] = color;
            if (graphColoringUtil(vertex + 1, numColors, graph, colors)) {
                return true;
            }
            colors[vertex] = 0;  // Backtrack: Remove the color if it doesn't lead to a solution
        }
    }
    return false;  // No valid color found for the vertex
}

// Function to solve the graph coloring problem
void graphColoring(int numVertices, int numColors, vector<vector<int>>& graph) {
    vector<int> colors(numVertices, 0);  // Initialize colors as 0 (no color)

    if (graphColoringUtil(0, numColors, graph, colors)) {
        cout << "Graph can be colored using " << numColors << " colors.\n";
        cout << "Coloring of vertices:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": Color " << colors[i] << "\n";
        }
    } else {
        cout << "Graph cannot be colored using " << numColors << " colors.\n";
    }
}

// Example usage
int main() {
    int numVertices, numEdges, numColors;

    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the number of colors: ";
    cin >> numColors;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    graphColoring(numVertices, numColors, graph);

    return 0;
}
