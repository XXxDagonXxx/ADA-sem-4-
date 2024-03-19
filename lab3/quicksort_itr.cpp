#include <iostream>
#include <fstream>
#include <stack>
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

void quicksort(int *arr,int low,int high){
        stack <int> stack;

    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
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