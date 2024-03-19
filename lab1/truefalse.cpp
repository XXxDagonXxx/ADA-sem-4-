#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("truefalsedata.txt", ios::app);
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
        fprintf(gnuplotPipe, "plot 'truefalsedata.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}

void truefalse(int a[],int k,int i){
    if (k==i+1){

    }
    else{
        a[k]='T' ;
        truefalse(a,k+1,i);
        a[k]='F';
        truefalse(a,k+1,i);
    }
}

void Algorithm() {
    double time1, time2, avgtime;
    for (int i = 27; i <= 30; i += 1) {
        int a[i];
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            int t=0;
            truefalse(a,t,i);
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
