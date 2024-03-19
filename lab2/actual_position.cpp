#include<iostream>
#include<cstdlib>
#include<fstream>
#include<time.h>
using namespace std;

void WriteDataToFile(int i, double avgTime){
    ofstream fout("data.txt", ios::app);
    if(fout.is_open()){
        fout<<i<<","<<avgTime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing data. "<<endl;
    }
}

int correct_pos(int * a,int j){
    int first=0;
    int last=j-1;
    int p=a[0];
    do{
        do{
            first=first+1;            
        }while(a[first]<=p);
        do{
            last=last-1;
        }while(a[last]>=p);
        if(first<last){
            int temp=a[last];
            a[last]=a[first];
            a[first]=temp;
        }
    }while(first<=last);
    a[0]=a[last];
    a[last]=p;
    return last; 
}

int main ()
{
    double time1,time2,avgtime;
    for (int j = 50000; j <= 100000; j += 500)
    {
        int a[j];
        for(int k=0;k<j;k++){
            a[k]=rand()%100;
        }
        time1=(double)clock();
        int t;
        for (int i=0;i<=9;i++){
        t= correct_pos(a,j);
        cout<<t<<" ";
        }
        time2=(double)clock();
        avgtime=(double)(time2-time1)/10.0;
        cout<<avgtime<<" ";
        WriteDataToFile(j,(avgtime*100));
    }
    return 0;
}