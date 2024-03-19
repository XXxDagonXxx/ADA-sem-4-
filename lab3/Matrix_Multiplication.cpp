#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

using namespace std;

void WriteDataToFile(int i, double avgtime) {
    ofstream fout("data.txt", ios::app);
    if (fout.is_open()) {
        fout << i << "-" << avgtime<< endl;
        fout.close();
    }
    else {
        cout << "Unable to open file for writing";
    }
}

int ** Matrix(int rows,int columns){
    int ** matrix= new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]= new int[columns];
    }
    return matrix;
}

void add_matrix(int ** result,int **matrixA,int **matrixB, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result[i][j]=matrixA[i][j]+matrixB[i][j];
        }
    }
}

void combine_matrix(int ** result,int ** C11, int **C12, int** C21, int** C22, int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result[i][j]=C11[i][j];
            result[i][j+size]=C12[i][j];
            result[i+size][j]=C21[i][j];
            result[i+size][j+size]=C22[i][j];
        }
    }
}

int** matrix_multiply(int ** A, int ** B, int size){
    if(size==1){
        int** C=Matrix(1,1);
        C[0][0]=A[0][0]*B[0][0];
        return C;
    }

    int newsize=size/2;
    int ** A11=Matrix(newsize,newsize);
    int ** A12=Matrix(newsize,newsize);
    int ** A21=Matrix(newsize,newsize);
    int ** A22=Matrix(newsize,newsize);

    int ** B11=Matrix(newsize,newsize);
    int ** B12=Matrix(newsize,newsize);
    int ** B21=Matrix(newsize,newsize);
    int ** B22=Matrix(newsize,newsize);

    for(int i=0;i<newsize;i++){
        for(int j=0;j<newsize;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+newsize];
            A21[i][j]=A[i+newsize][j];
            A22[i][j]=A[i+newsize][j+newsize];
            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+newsize];
            B21[i][j]=B[i+newsize][j];
            B22[i][j]=B[i+newsize][j+newsize];
        }
    }
    int ** P1=matrix_multiply(A11,B11,newsize);
    int ** P2=matrix_multiply(A12,B21,newsize);
    int ** P3=matrix_multiply(A11,B12,newsize);
    int ** P4=matrix_multiply(A12,B22,newsize);
    int ** P5=matrix_multiply(A21,B11,newsize);
    int ** P6=matrix_multiply(A22,B12,newsize);
    int ** P7=matrix_multiply(A21,B21,newsize);
    int ** P8=matrix_multiply(A22,B22,newsize);

    int **C11=Matrix(newsize,newsize);
    int **C12=Matrix(newsize,newsize);
    int **C21=Matrix(newsize,newsize);
    int **C22=Matrix(newsize,newsize);

    add_matrix(C11,P1,P2,newsize);
    add_matrix(C12,P3,P4,newsize);
    add_matrix(C21,P5,P6,newsize);
    add_matrix(C22,P7,P8,newsize);

    int **result=Matrix(size,size);
    combine_matrix(result,C11,C12,C21,C22,newsize);
}

int main(){
    double avgtime,time1,time2;
    for(int i=2;i<200;i=2*i){
        int **A=Matrix(i,i);
        int **B=Matrix(i,i);
    

    for(int j=0;j<i;j++){
        for(int k=0;k<i;k++){
            A[j][k]=rand();
            B[j][k]=rand();
        }
    }
    time1=double(clock());
    for(int k=0;k<10;k++){
        int ** result=matrix_multiply(A,B,i);
    }
    time2=double(clock());
    avgtime=(time2-time1)/10;
    cout<<i<<"-"<<avgtime<<endl;
    WriteDataToFile(i,avgtime);
  }
  return 0;
}