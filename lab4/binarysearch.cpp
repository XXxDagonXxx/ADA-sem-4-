#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << "-" << avgtime << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void Generate(int *a, int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand();
    }
}

int BinarySearch(int *a, int num, int size) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == num) {
            return mid;
        } else {
            if (a[mid] > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

void Algorithm() {
    double time1, time2, avgtime;
    for (int size = 10000000; size <= 100000000; size += 1000000) {
        int *a = new int[size];
        Generate(a, size);
        int num = rand() % size;
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            int ans = BinarySearch(a, num, size);
        }

        time2 = (double)clock();
        avgtime = (time2 - time1) / 10.0;
        cout << size << "-" << avgtime << endl;
        WriteDataToFile(size, avgtime);
        
        delete[] a;
    }
}

int main() {
    Algorithm();
    return 0;
}
