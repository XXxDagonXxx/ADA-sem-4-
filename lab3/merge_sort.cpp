#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout<< i << " " << avgtime << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void merge(int *list,int low, int mid, int high){
    int *result=new int[2*high];
    int lowA=low; int highA=mid; int lowB=mid+1; int highB=high;
    int i=0;
    while(lowA<=highA && lowB<=highB){
        if(list[lowA]<=list[lowB]){
            result[i]=list[lowA];
            lowA++;
        }
        else{
            result[i]=list[lowB];
            lowB++;
        }
        i++;
    }
        while (lowA < highA) {
        result[i] = list[lowA];
        lowA++;
        i++;
    }
    while (lowB < highB) {
        result[i] = list[lowB];
        lowB++;
        i++;
    }  
    delete[] result;
}

void merge_sort(int *list,int low,int high){
    if(low<=high){
        int mid=floor((low+high)/2);
        merge_sort(list,low,mid);
        merge_sort(list,mid+1,high);
        merge(list,low,mid,high);
    }
}

int main() {
    srand(time(NULL));
    double time1, time2, avgtime;
    const int minsize=1000;
    const int maxsize=100000;
    const int step=1000;
    const int iterations=10;
    for (int i = minsize; i <= maxsize; i += step) {
        int *list=new int[i];
        int count=0;
        for (int k=0;k<i;k++){
            list[k]=rand();
        }
        time1 = (double)clock();
        for (int k = 0; k < iterations; k++) {
            merge_sort(list,0,i-1);
            count++;
        }
        time2 = (double)clock();
        avgtime = (time2 - time1) / count;
        cout << i << "-" << avgtime << endl;
        WriteDataToFile(i, avgtime);
        delete[] list;
    }
    return 0;
}