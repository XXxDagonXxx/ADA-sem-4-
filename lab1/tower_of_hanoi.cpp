#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("toh.txt", ios::app);
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
        fprintf(gnuplotPipe, "plot 'toh.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}

void Tower_of_Hanoi(int n, char source, char destination, char sparse){
    if(n==1){
    //    cout<<"Move from "<<source<<" to"<< destination<<endl;
    }
    else{
        Tower_of_Hanoi(n-1,source,sparse,destination);
        Tower_of_Hanoi(1,source,destination,sparse);
        Tower_of_Hanoi(n-1,sparse,destination,source);
    }
}

void Algorithm() {
    double time1, time2, avgtime;
    for (int i = 2; i <= 20; i += 1) {
        int a[i];
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            int t=0;
            Tower_of_Hanoi(i,'A','B','C');
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
