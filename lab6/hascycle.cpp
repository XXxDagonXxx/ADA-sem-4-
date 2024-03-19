#include <iostream>
using namespace std;

int find(int *parent, int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    } else {
        return find(parent, parent[vertex]);
    }
}

void unionset(int *parent, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        parent[rootU] = rootV;
    }
}

bool hasCycle(int edges[][2], int *parent, int num_edges) {
    for (int i = 0; i < num_edges; i++) {
        int rootI = find(parent, edges[i][0]);
        int rootJ = find(parent, edges[i][1]);
        if (rootI == rootJ) {
            return true;
        }
        unionset(parent, rootI, rootJ);
    }
    return false;
}

int main() {
    int num_vertex = 5;
    int *parent = new int[num_vertex];
    
    for (int i = 0; i < num_vertex; i++) {
        parent[i] = i;
    }

    int edges[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int num_edges = sizeof(edges) / sizeof(edges[0]);

    if (hasCycle(edges, parent, num_edges)) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    delete[] parent;
    return 0;
}
