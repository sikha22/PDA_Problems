//Call by value and Call by reference

#include<iostream>
using namespace std;

int sum(int a , int b){
    int c = a +b;
    return c;
}
//This will not swap the values
void swap(int a, int b){
    int temp = a;
    a=b;
    b=temp;
}
//call by reference using pointer
//This will swap the values of a and b using pointer reference
void swapPointer(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//call by reference using c++ reference variable
void swapReferenceVar(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int num1,num2;
    cout<<"Enter num1: "<<endl;
    cin>>num1;
    cout<<"Enter num2: " <<endl;
    cin>>num2;
    cout<<"The sum of num1 and num2 is : "<<sum(num1,num2)<<endl;
    // swap(num1,num2); //This will not swap the values
    // swapPointer(&num1,&num2);  //This will swap the value of a and b using pointer reference
    swapReferenceVar(num1,num2); //This will also swap the value of a and b using reference variable
    cout<<"The value of num1 is "<<num1<<" and num2 is "<< num2<<endl;
    return 0;
}