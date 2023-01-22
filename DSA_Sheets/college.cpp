#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    string tmp;
    vector<string> s;
	fstream college;
	college.open("college.txt",ios::out);
	if (!college) {
		cout<<"File not created!";
	}
	else {
		cout<<"College.txt created successfully!\n";
		cout<<"Input 3 College Names : \n";
		for(int i=0; i<3; i++)
        {
            getline(cin,tmp);
            s.push_back(tmp);
            college<<s[i]<<"\n";
        }
	}
	fstream university;
	university.open("university.txt",ios::out);
	if (!university) {
		cout<<"File not created!";
	}
	else {
		cout<<"\nUniversity.txt created successfully!\n";
		for(int i=0; i<3; i++)
        {
            university<<s[i]<<"\n";
        }
        cout<<"Content of College.txt is Copied in University.txt\n\n";
	}
	cout<<"Content of file University.txt :- \n";
	for(int i=0; i<3; i++)
    {
        cout<<s[i]<<"\n";
    }
	return 0;
}
