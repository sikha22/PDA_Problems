// STRUCTURE , UNION 

#include<iostream>
using namespace std;

struct employee
{
    /* data */
    int eId;
    string eName;
    float eSalary;
} shikha;

union student
{
    /* data */
    //you can use only one at a time because memory is sharing .
    int sId;
    char sName;
    float sMarks;
} sharma;


int main(){
    /** STRUCTURE START**/

    // struct employee shikha;
    // shikha.eId = 7;
    // shikha.eName = "Ananya";
    // shikha.eSalary = 100000000;
    // cout<<"The ID of employee is " << shikha.eId<<endl;
    // cout<<"The Name of employee is " << shikha.eName<<endl;
    // cout<<"The salary of employee is " << shikha.eSalary<<endl;

    /** STRUCTURE END**/

    /*UNION START*/

    // sharma.sId=5;
    // cout<<"The ID of STudent is "<<sharma.sId<<endl;

    /** UNION END**/

    /** ENUM START**/
    enum Meal{breakfast,lunch,dinner,eveningSnack};
    Meal m1 = eveningSnack;
    cout<<m1<<endl;
    cout<<breakfast<<endl;
    cout<<lunch<<endl;
    cout<<dinner<<endl;
    cout<<eveningSnack<<endl;
    /** ENUM END**/

    return 0;
}