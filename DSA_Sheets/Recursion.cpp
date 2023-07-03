// RECURSION
#include<iostream>
using namespace std;

//Factorial series  5 = 5*4*3*2*1
int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n * factorial(n-1);
}

//Fibonacci Series 1 1 2 3 5 8 13 21 34
int fibonacci(int n){
    if(n<2){
        return 1;
    }
    return fibonacci(n-2) + fibonacci(n-1);
}
int main(){
    int num1;
    cout<<"ENter Number : ";
    cin>>num1;
    cout<<"The factorial of "<<num1<<" is : "<<factorial(num1)<<endl; //factorial
    cout<<"The fibonnaci series at position " << num1 << " is : "<<fibonacci(num1)<<endl; //Fibonacci series
    return 0;
}