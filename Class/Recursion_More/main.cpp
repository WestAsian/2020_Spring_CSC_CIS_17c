/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 29th, 2020, 12:54 PM
 * Purpose:  More Recursions
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Comparitive Functions
#include <iomanip>    //Formatting Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants
//Science and Math, Conversions, Higher Dimensions
//const to follow
const float PId4=atan(1);//45 degree angle

//Function Prototypes
float  expRec(float);      //Another way to do the exp(), not accurate
double expRec(double);     //The accurate approximations
int    bCoef(int,int);     //Binomial Coefficients and Pascal's Triangle
int    gcd(int,int);       //Euclid's, the greatest common denominator
float  sinAprx(float);     //Mutual Recursion with the cos
float  cosAprx(float);     //Mutual Recursion with the sin

//Execution Starts Here
int main(int argc, char** argv){
    //Set Random Number Seed Here
    
    //Declare Variables - Known and Unknown, units, range, description
    float fx;      //Floating Real
    double dx;     //Floating Double
    int rows;      //Size of the Triangular matrix of Pascal's Triangle
    int num,denom; //Simplifying a fraction numerator/denominator
    
    
    //Initialize Variables
    fx=1;
    dx=1;
    rows=20;
    num=100;
    denom=350;
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    cout<<"Approximate float  exponential ~ e^"<<fx<<" = "<<expRec(fx)<<endl;
    cout<<"Approximate double exponential ~ e^"<<dx<<" = "<<expRec(dx)<<endl;
    cout<<"Exact              exponential = e^"<<fx<<" = "<<exp(fx)<<endl;
    cout<<endl<<"Pascal's Triangle"<<endl;
    for(int row=0;row<=rows;row++){
        cout<<"n = "<<setw(2)<<row<<"      ";
        for(int col=0;col<=row;col++){
            cout<<bCoef(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Output the ratio as relative prime"<<endl;
    cout<<num<<"/"<<denom<<" = "
            <<num/gcd(num,denom)<<"/"<<denom/gcd(num,denom)<<endl;
    
    
    cout<<endl<<endl;
    cout<<"angle = "<<PId4<<" radians"<<endl;
    cout<<"sin approx("<<PId4<<") = "<<sinAprx(PId4)<<endl;
    cout<<"sin  exact("<<PId4<<") = "<<sin(PId4)<<endl;
    cout<<"cos approx("<<PId4<<") = "<<cosAprx(PId4)<<endl;
    cout<<"cos  exact("<<PId4<<") = "<<cos(PId4)<<endl;
    
    
    //Clean up - File closing, memory deallocation, etc....

    //Exit Stage Right!
    return 0;
}

//Function Implementations
float sinAprx(float x){
    //Base Case
    float tol=1.0e-6f;
    if(abs(x)<tol)return x;
    //Recursive Call
    return 2*sinAprx(x/2)*cosAprx(x/2);
}

float cosAprx(float x){
    //Base Case
    float tol=1.0e-6f;
    if(abs(x)<tol)return 1-x*x/2;
    //Recursive Call
    float a=sinAprx(x/2);
    float b=cosAprx(x/2);
    return b*b-a*a;
}

int gcd(int m,int n){
    //Base Case
    if(m==0)return n;
    //Recursive Call
    if(m>=n)return gcd(m%n,n);
    return gcd(n%m,m);
}


int bCoef(int n,int j){
    //Base Case
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursive Call
    return bCoef(n-1,j-1)+bCoef(n-1,j);
}

double expRec(double x){
    //Base Case
    double tol=1.0e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursive Call
    double a=expRec(x/2.0f);
    return a*a;
}

float expRec(float x){
    //Base Case
    float tol=1.0e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursive Call
    float a=expRec(x/2.0f);
    return a*a;
}