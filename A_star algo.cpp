#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Node structure for representing a grid cell
struct Node {
    int x;             // x-coordinate of the cell
    int y;             // y-coordinate of the cell
    int f;             // f-value of the cell (f = g + h)
    int g;             // g-value of the cell (distance from the start)
    int h;             // h-value of the cell (heuristic distance to the goal)
    bool obstacle;     // flag indicating if the cell is an obstacle
    Node* parent;      // pointer to the parent node

    Node(int x, int y) : x(x), y(y), f(0), g(0), h(0), obstacle(false), parent(nullptr) {}
};

// Helper function to calculate the Manhattan distance between two nodes
int calculateManhattanDistance(Node* current, Node* goal) {
    return abs(current->x - goal->x) + abs(current->y - goal->y);
}

// A* algorithm function
vector<Node*> aStar(Node* start, Node* goal, vector<vector<Node>>& grid) {
    // Priority queue for the open set
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> openSet;

    // Set the g and h values of the start node
    start->g = 0;
    start->h = calculateManhattanDistance(start, goal);
    start->f = start->g + start->h;

    // Add the start node to the open set
    openSet.push(make_pair(start->f, start));

    while (!openSet.empty()) {
        // Get the node with the minimum f-value from the open set
        Node* current = openSet.top().second;
        openSet.pop();

        // Check if the current node is the goal node
        if (current == goal) {
            vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Generate the neighbors of the current node
        vector<Node*> neighbors;
        int x = current->x;
        int y = current->y;

        if (x > 0)
            neighbors.push_back(&grid[x - 1][y]);     // Left neighbor
        if (x < grid.size() - 1)
            neighbors.push_back(&grid[x + 1][y]);     // Right neighbor
        if (y > 0)
            neighbors.push_back(&grid[x][y - 1]);     // Top neighbor
        if (y < grid[0].size() - 1)
            neighbors.push_back(&grid[x][y + 1]);     // Bottom neighbor

        // Process each neighbor
        for (Node* neighbor : neighbors) {
            // Skip if the neighbor is an obstacle or has already been visited
            if (neighbor->obstacle || neighbor->parent)
                continue;

            // Calculate the new g-value for the neighbor
            int newG = current->g + 1;

            // Check if the new g-value is better than the current g-value
            if (newG < neighbor->g) {
                neighbor->g = newG;
                neighbor->h = calculateManhattanDistance(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;

                // Add the neighbor to the open set
                openSet.push(make_pair(neighbor->f, neighbor));
            }
        }
    }

    // No path found
    return {};
}

// Function to print the grid
void printGrid(const vector<vector<Node>>& grid) {
    for (const vector<Node>& row : grid) {
        for (const Node& node : row) {
            if (node.obstacle)
                cout << "X ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    // Define the size of the grid
    int rows = 5;
    int cols = 5;

    // Create the grid
    vector<vector<Node>> grid(rows, vector<Node>(cols, Node(0, 0)));

    // Set the coordinates for each node in the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
        }
    }

    // Set some nodes as obstacles
    grid[1][1].obstacle = true;
    grid[2][2].obstacle = true;
    grid[3][1].obstacle = true;
    grid[3][2].obstacle = true;

    // Set the start and goal nodes
    Node* start = &grid[0][0];
    Node* goal = &grid[rows - 1][cols - 1];

    // Run A* algorithm
    vector<Node*> path = aStar(start, goal, grid);

    // Print the grid with the path
    for (Node* node : path) {
        grid[node->x][node->y].obstacle = false;
    }
    printGrid(grid);

    return 0;
}
