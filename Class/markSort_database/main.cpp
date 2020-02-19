/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 19, 2020, 11:51 AM
 * Purpose:  Database Sort
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
int *filData(int);
int *filIndx(int);
void destroy(int *);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void mrkSort(int *,int *,int);

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables - Known and Unknown, units, range, description
    int size=100;
    int *array;
    int *indx;
    
    //Initialize Variables
    array=filData(size);
    indx=filIndx(size);
    
    //Display before sort
    cout<<"Data Array Before Sort"<<endl;
    prntAry(array,size,10);
    cout<<"Indexed Array Before Sort"<<endl;
    prntAry(indx,size,10);
    
    //Map inputs to outputs -> i.e. process the inputs
    mrkSort(array,indx,size);
    
    //Display the outputs
    cout<<"Data Array After Sort"<<endl;
    prntAry(array,size,10);
    cout<<"Indexed Array After Sort"<<endl;
    prntAry(indx,size,10);
    cout<<"Data Array After Sort Displayed with Indices"<<endl;
    prntAry(array,indx,size,10);
    
    //Clean up - File closing, memory deallocation, etc....
    destroy(array);
    destroy(indx);

    //Exit Stage Right!
    return 0;
}

void mrkSort(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[indx[i]]>a[indx[j]]){
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
    }
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[indx[i]]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
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

void destroy(int *a){
    delete []a;
}

int *filData(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//[10-99]
    }
    return array;
}

int *filIndx(int n){
    int *indx=new int[n];
    for(int i=0;i<n;i++){
        indx[i]=i;
    }
    return indx;
}