//FUNCTION OVERLOADING

#include<iostream>
using namespace std;

int volumeCylinder(double r,float h){
    return(3.14*r*r*h);
}

int volumeCube(int a){
    return a*a*a;
}

int volumeCuboid(int l,int h, int b){
    return (l*b*h);
}

int main(){
    cout<<"The volume of Cylinder is : "<<volumeCylinder(3,4)<<endl;
    cout<<"The volume of cube is : "<<volumeCube(5)<<endl;
    cout<<"The volume of Cuboid is : "<<volumeCuboid(2,3,4)<<endl;
    return 0;
}