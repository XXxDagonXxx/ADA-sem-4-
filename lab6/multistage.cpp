#include<iostream>
#include<cstdlib>
using namespace std;

int min_vertex(int key, int ** cost, int *fcost, int n) {
    int min_cost = 10000;
    int r = -1; 
    for(int i = key+1; i<n; i++) {
        if(cost[key][i] != 0) {
            if(cost[key][i] + fcost[i] < min_cost) {
                min_cost = cost[key][i] + fcost[i];
                r = i;
            }
        } 
    }
    return r;
}

void fcostfind(int ** cost, int n) {
    int fcost[n];
    int d[n];
    fcost[n-1] = 0; 
    int r;
    for(int j = n-2; j >= 0; j--) {
        r = min_vertex(j, cost, fcost, n);
        d[r] = j;
        fcost[j] = cost[j][r] + fcost[r];
    }
    cout << "Path is as follows:" << endl;
    cout << "1 ";
    for(int i = 1; i < n-1; i++) {
        cout << "->> " << d[i-1] << " ";
    }
    cout << "->> " << n << endl;

cout<<"Complete Cost: "<<fcost[0];
}

int main()
{
    int n;
    cout<<"Enter total vertices:";
    cin>>n;
        int *cost = new int[n];
    for (int i = 0; i <n; i++) {
        cost[i] = new int[n];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cout<<"cost from vertex "<<i+1<<" to vertex "<<j+1<<":";
            cin>>cost[i][j];
        }
    }
    fcostfind(cost,n);
    return 0;
}
