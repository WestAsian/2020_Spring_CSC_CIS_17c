/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 19, 2020, 11:51 AM
 * Purpose:  Simple Sort
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Library
#include <ctime>      //Time Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow

//Function Prototypes
int *filAray(int);
int **filAray(int *,int,int,int);
void destroy(int *);
void destroy(int **,int);
void prntAry(int *,int,int);
void prntAry(int **,int,int);
void mrkSort(int *,int);


//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables - Known and Unknown, units, range, description
    int size=100;
    int row=10,col=10;
    int perLine=10;
    int *array;
    int **copy;
    
    //Initialize Variables
    array=filAray(size);
    
    //Display before sort
    prntAry(array,size,perLine);
    
    //Map inputs to outputs -> i.e. process the inputs
    mrkSort(array,size);
    copy=filAray(array,size,row,col);
    
    //Display the outputs
    prntAry(array,size,perLine);
    prntAry(copy,row,col);
    
    //Clean up - File closing, memory deallocation, etc....
    destroy(array);
    destroy(copy,row);

    //Exit Stage Right!
    return 0;
}

int **filAray(int *a,int s,int r,int c){
    //Allocate Memory
    int **array2D=new int*[r];
    if(r*c==s){
        for(int i=0;i<r;i++){
            array2D[i]=new int[c];
        }
    
        //Transfer Data and Fill
        for(int cnt=0,row=0;row<r;row++){
            for(int col=0;col<c;col++){
                array2D[row][col]=a[cnt++];
            }
        }
    }else{
        array2D=0;
    }
    return array2D;
}

void mrkSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void prntAry(int **a,int r,int c){
    cout<<endl;
    for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                cout<<a[row][col]<<" ";
            }
            cout<<endl;
        }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void destroy(int **a,int r){
    for(int i=0;i<r;i++){
            delete []a[i];
    }
    delete []a;
}

void destroy(int *a){
    delete []a;
}

//Function Implementations
int *filAray(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//[10-99]
    }
    return array;
}