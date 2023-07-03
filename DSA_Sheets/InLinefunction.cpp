// INLINE FUNCTION

#include<iostream>
using namespace std;
//INLINE
inline int product(int a,int b){
    return a*b;
}
//DEFAULT
float moneyReceived(int currentMoney , float factor = 1.04){
    return currentMoney*factor;
}
int main(){
    int num1,num2;
    cout<<"Enter num1 : ";
    cin>>num1;
    cout<<"Enter num2 : ";
    cin>>num2;
    cout<<"Product of "<<num1<<" and "<<num2 <<" is : "<<product(num1,num2)<<endl;
    int money = 100000;
    cout<<"If you have "<<money<<" Rs in your account, then you will receive "<<moneyReceived(money)<<" Rs after 1 year"<< endl;
    cout<<"For VIP : If you have "<<money<<" Rs in your account, then you will receive "<<moneyReceived(money,1.1)<<" Rs after 1 year"<< endl;
    return 0;
}