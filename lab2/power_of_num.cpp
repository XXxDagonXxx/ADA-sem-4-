#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime_iter, double avgtime_rec) {
    ofstream fout("combined_data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << " " << avgtime_iter << " " << avgtime_rec << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

// void PlotChart() {
//     FILE *gnuplotPipe = _popen("gnuplot -persist", "w");
//     if (gnuplotPipe) {
//         fprintf(gnuplotPipe, "plot 'combined_data.txt' using 1:2 with linespoints title 'Iterative' linecolor rgb 'blue', '' using 1:3 with linespoints title 'Recursive' linecolor rgb 'red'\n");
//         _pclose(gnuplotPipe);
//     } else {
//         cerr << "Gnuplot not found. Please install Gnuplot." << endl;
//     }
// }

int PowerOfNum(int x, int i) {
    int ans = 1;
    for (int j = 0; j < i; j++) {
        ans = ans * x;
    }
    return ans;
}

int Power_Of_Num(int x, int i) {
    int power=1;
    while(i!=0){
        if(i%2==0){
          x=x*x;
          i=i/2;  
        }
        else{
            power=power*x;
            i=i-1;
        }
    }
    return power;
}

int main() {
    double time1, time2, avgtime_iter, avgtime_rec;
    
    for (int i = 100; i <= 10000; i=i+100) {
        time1 = (double)clock();
        cout<<"Power of number using Iteration!";
        for (int k = 0; k <= 15; k=k+5) {
            int ans = PowerOfNum(i, 2);
            cout<<ans<<" ";
        }
        time2 = (double)clock();
        avgtime_iter = (time2 - time1) / 4.0;
        cout<<" - "<<avgtime_iter*100 << endl;
        
        cout<<"Power of number using divide and conquer technique!";

        time1 = (double)clock();
        for (int k = 0; k <= 15; k=k+5) {
            int ans=Power_Of_Num(i, 2);
            cout<<ans<<" ";
        }
        time2 = (double)clock();
        avgtime_rec = (time2 - time1) / 4.0;
        cout<<" - "<< avgtime_rec*100 << endl;
        WriteDataToFile(i, (avgtime_iter*100), (avgtime_rec*100));
    }
    // PlotChart();
    return 0;
}
