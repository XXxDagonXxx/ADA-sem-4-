#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data1.txt", ios::app);
    if (fout.is_open()) {
        fout<< i << " " << avgtime << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void PlotChart() {
    FILE *gnuplotPipe = _popen("gnuplot -persist", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "plot 'data1.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}

void Generate(int a[], int i) {
    for (int j = 0; j <= i; j++) {
        a[j] = rand();
    }
}

int sum(int a[],int n){
    int sum=0;
    for(int j=0;j<=n;j++){
        sum=sum+a[j];
    }
    return sum;
}

void Algorithm() {
    double time1, time2, avgtime;
    for (int i = 1; i <= 519000; i += 1000) {
        int a[i];
        Generate(a, i);
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            int ans=sum(a,i);

        }

        time2 = (double)clock();
        avgtime = (time2 - time1) / 10.0;
        cout << i << "-" << avgtime << endl;
        WriteDataToFile(i, avgtime);
    }
    PlotChart();
}

int main() {
    Algorithm();
    return 0;
}
