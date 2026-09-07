#include <iostream>
#include <string.h>
using namespace std;

class Student{
	int i, roll;
	string name;
	float avg=0, m[3];
	public:
	void read();
	void disp();
};
void Student::read(){
	cout<<"Enter student name: ";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter roll no. : ";
	cin>>roll;
	cout<<"Enter Marks:" ;
	for(i=0;i<3;i++)
		cin>>m[i];
}
void Student::disp(){
	avg=0;
	cout<<name<<"\n"<<roll<<endl;
	for(i=0;i<3;i++){
		cout<<m[i]<<"\t";
		avg+=m[i];
	}
	cout<<endl;
	avg=avg/3;
	cout<<"Average: "<<avg<<endl;
}

int main(){
	Student s;
	s.read();
	s.disp();
	return 0;
}
