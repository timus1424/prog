/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <string.h>
#include <iostream>
using namespace std;

class student{
    int roll;
    string name;
public:
    void read();
    void disp();
//friend temp sumn(temp ob1, temp ob2);
};

void student::read()
{
    cout<<"Enter roll no.:";
    cin>>roll;
    cout<<"Enter name: \n";
    cin.ignore();
    getline(cin,name);
}

void student::disp()
{
    cout<<"\nStudent details : \n";
    cout<<roll<<"\t"<<name<<endl;
}

int main()
{
    int i, n;
    cout<<"Enter no. of student: \n";
    cin>>n;
    student s[n];
    for(i=0;i<n;i++){
        s[i].read();
    }
    for(i=0;i<n;i++){
        s[i].disp();
    }
    return 0;
}
