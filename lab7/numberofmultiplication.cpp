#include <iostream>
#include <limits>
using namespace std;

int Matrix_Chain(int **S, int p[], int i, int j) {
    if (i == j) {
        return 0;
    }
    int minresult = numeric_limits<int>::max(); // Use numeric_limits to get maximum value
    for (int k = i; k < j; k++) {
        int count = Matrix_Chain(S, p, i, k) + Matrix_Chain(S, p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < minresult) {
            minresult = count;
            S[i][j] = k;
        }
    }
    return minresult;
}

void Print(int** S, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        Print(S, i, S[i][j]);
        Print(S, S[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int arr[] = { 3,5,5,4,3,2,4 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int** S = new int*[N];
    for (int a = 0; a < N; a++) {
        S[a] = new int[N];
        for (int b = 0; b < N; b++) {
            S[a][b] = -1; // Initialize S to -1
        }
    }
    
    cout << "Total number of multiplications: " << Matrix_Chain(S, arr, 1, N - 1) << endl;
    cout << "Multiplication order: ";
    Print(S, 1, N - 1);
    
    // Deallocate memory
    for (int a = 0; a < N; a++) {
        delete[] S[a];
    }
    delete[] S;
    
    return 0;
}
