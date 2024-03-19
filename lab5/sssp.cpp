#include <iostream>
#include <fstream>
#include <time.h>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

void sssp(int n, int **cost, int v, int *dist) {
    bool *s = new bool[n];
    for (int i = 0; i < n; i++) {
        dist[i] = cost[v][i];
        s[i] = false;
    }
    s[v] = true;
    for (int j = 1; j < n; j++) { 
        int u;
        int minDist = INF;
        for (int i = 0; i < n; i++) {
            if (!s[i] && dist[i] < minDist) {
                u = i;
                minDist = dist[i];
            }
        }
        s[u] = true; 
        for (int w = 0; w < n; w++) {
            if (!s[w] && dist[w] > dist[u] + cost[u][w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
    delete[] s;
}


int main() {
    int vertices;
    cout<<"Enter number of vertices:";
    cin>>vertices;
    int **cost = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        cost[i] = new int[vertices];
    }
    int *dist = new int[vertices];
    for(int i=0;i<vertices;i++){
        for (int j=0;j<vertices;j++){
            cout<<"Enter cost from Vertex: "<<i+1<<" to "<<j+1<<" :";
            cin>>cost[i][j];
        }
    }
    cout<<"Enter source from which you want to find shortest distance of all posible vertex:";
    int source;
    cin>>source;

    sssp(vertices, cost, source-1, dist);

    for (int i = 0; i < vertices; i++) {
        cout << "Distance from vertex "<<source<<" to " << i+1 << ": " << dist[i] <<endl;
    }

    for (int i = 0; i < vertices; i++) {
        delete[] cost[i];
    }
    delete[] cost;
    delete[] dist;

    return 0;
}
