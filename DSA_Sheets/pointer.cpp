//POINTER

#include<iostream>
using namespace std;

int main(){
    int a =9;
    int* b = &a;
   /*
    int* b;
    b = &a;
    */ 
   
    // & = address of operator
    cout<<"The address of a is " <<b<<endl;
    cout<<"The address of a is " << &a<<endl;

    // * = (value at) dereference operator
    cout<<"The value at address b is "<<*b<<endl;

    // POINTER TO POINTER
    int** c = &b;
    cout<<"The address of b is " << c<<endl;
    cout<<"The address of b is " << &b<<endl;
    cout<<"The value at address c is "<<**c<<endl;
    return 0;
}