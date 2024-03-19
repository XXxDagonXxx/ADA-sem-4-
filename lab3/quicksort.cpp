#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

using namespace std;

void WriteDataToFile(int i,int avgtime){
    ofstream fout("data.txt",ios::app);
    if(fout.is_open()){
        fout<<i<<"-"<<avgtime<<endl;
        fout.close();
    }
    else{
        cout<<"Unable to open file for writing";
    }
}

int partition(int *arr,int start,int end){
    int key=arr[start];
    int high=end;
    int low=start+1;
    do{
        do{
            low++;
        }while(arr[low]<key);
        do{
            high--;
        }while(arr[high]>key);
        if(low<high){
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
        }
    }while(low<high);
    arr[start]=arr[high];
    arr[high]=key;

    return high;
}

void quicksort(int *arr,int start,int end){
    if(start<end){
        int j=partition(arr,start,end);
        quicksort(arr,start,j-1);
        quicksort(arr,j+1,end);
    }
}

int main(){
    double time1,time2,avgtime;
    for(int i=100;i<=100000;i+=1000){
        int *list1=new int[i];
        for(int k=0;k<i;k++){
            list1[k]=rand();
        }
        time1=double(clock());
        for(int j=0;j<10;j++){
            quicksort(list1,0,i-1);
        }
        time2=double(clock());
        avgtime=(time2-time1)/10;
        cout<<i<<"-"<<avgtime<<endl;
        WriteDataToFile(i,avgtime);
    }
    return 0;
}