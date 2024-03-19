#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
void WriteDataToFile(int i, double avgtime_iter , double avgtime_rec) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << " " << avgtime_iter << " " << avgtime_rec << endl;
        fout.close();
    } else {
        cerr << "Unable to open file for writing data." << endl;
    }
}

void MaxMinIterative(int *a, int low, int high){
    for(int i=low;i<=high;i++){
        for(int j=i+1;j<=high;j++){
            if(a[i]>a[j]){
                int t= a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    // cout<<"MAX: "<<a[high]<<" MIN: "<<a[low]<<endl;
}
void MaxMin(int* a, int low, int high){
    int max, min,mid,max1,min1;
    if(low ==high){
        max=a[low];
        min=a[low];
    }
    else{
        mid=(low+high)/2;
        MaxMin(a,low, mid);
    }
    if(low ==high){
        max1=a[low];
        min1=a[low];
    }
    else{
        mid=(low+high)/2;
        MaxMin(a,mid+1,high);
    }
    if(max<max1){
        max=max1;
    }
    if(min>min1){
        min=min1;
    }
    // cout<<"Max el"<<max<<" Min el"<<min<<endl;
}
int main(){
    double avgtime_itr,avgtime_rec,time1,time2;
    for(int i=100;i<1000;i+=100){
        int *a = new int [i];
        for(int j=0;j<i;j++){
            a[j]=rand();
        }
        time1 =(double)clock();
        for(int k=0;k<10;k++){
            MaxMin(a,1,i);
        }
        time2=(double)clock();
        avgtime_rec=(double)(time2-time1)/10;
        
        int *b = new int [i];
        for(int j=0;j<i;j++){
            b[j]=rand();
        }
        time1 =(double)clock();
        for(int k=0;k<10;k++){
            MaxMinIterative(b,0,i-1);
        }
        time2=(double)clock();
        avgtime_itr=(double)(time2-time1)/10;
        cout<<i<<" "<<avgtime_itr<<" "<<avgtime_rec*100<<endl;
        WriteDataToFile(i,avgtime_itr,avgtime_rec*100);
    }

    return 0;
}