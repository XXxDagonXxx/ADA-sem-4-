#include <iostream>
#include <limits>

using namespace std;

const int infinity = 1000000000;
const int max_vertices = 6;

void Prims(int n, int cost[][max_vertices], int final[][2]) {
    int near[max_vertices];
    int minCostVertex = 0;

    int minCost = infinity;
    for (int i = 1; i < n; i++) {
        near[i] = 0;
        if (cost[i][0] < minCost) {
            minCost = cost[i][0];
            minCostVertex = i;
        }
    }

    for (int i = 1; i < n; i++) {
        final[i][1] = minCostVertex;
        final[i][2] = near[minCostVertex];

        near[minCostVertex] = -1;

        for (int j = 1; j < n; j++) {
            if (near[j] != -1 && cost[j][minCostVertex] < cost[j][near[j]]) {
                near[j] = minCostVertex;
            }
        }

        minCost = infinity;
        for (int j = 1; j < n; j++) {
            if (near[j] != -1 && cost[j][near[j]] < minCost) {
                minCost = cost[j][near[j]];
                minCostVertex = j;
            }
        }
    }
}

int main() {
    int vertices = 6;
    int cost[6][6] = {
        {0, 3, 4, 8, 0, 4},
        {3, 0, 0, 0, 3, 2},
        {4, 0, 0, 0, 0, 7},
        {8, 0, 0, 0, 6, 8},
        {0, 3, 0, 6, 0, 5},
        {4, 2, 7, 8, 5, 0}
    };

    int n = vertices;
    int final[max_vertices][2];
    Prims(n, cost, final);

    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 1; i < n; i++) {
        cout << final[i][1] << " - " << final[i][2] << endl;
    }

    return 0;
}
