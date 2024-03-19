#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data2.txt", ios::app);
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
        fprintf(gnuplotPipe, "plot 'data2.txt' with linespoints title 'Average Time'\n");
        _pclose(gnuplotPipe);
    } else {
        cerr << "Gnuplot not found. Please install Gnuplot." << endl;
    }
}

void Generate(char a[], int i) {
    for (int j = 0; j <= i; j++) {
        a[j] = 'a'+rand()%26;
    }
}


void permutationGen(char a[],int k,int i){
    if(k==i){
        
    }
    else{
        for(int j=k;j<i;j++){
            char temp=a[k];
            a[k]=a[j];
            a[j]=temp;
            permutationGen(a,k+1,i);
            temp=a[k];
            a[k]=a[j];
            a[j]=temp;
        }
    }
}

void Algorithm() {
    double time1, time2, avgtime;
    for (int i = 1; i <=0; i += 1) {
        char a[i];
        Generate(a, i);
        time1 = (double)clock();
        for (int k = 0; k < 10; k++) {
            int t=0;
            permutationGen(a,t,i);
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
