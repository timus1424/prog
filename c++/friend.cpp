#include <iostream>
using namespace std;
class temp;

class temp{
    int a,b;
public:
    void read();
    void disp();
friend temp sumn(temp ob1, temp ob2);
};

void temp::read()
{
    cout<<"Enter 2 nos. \n";
    cin>>a>>b;
}

void temp::disp()
{
cout<<"The no. is : \n";
cout<<a<<" & "<<b<<endl;
}

temp sumn (temp ob1,temp ob2)	//temp here is the return type, the lack of :: shows it is not a member function.
{
temp ob3;
ob3.a=ob1.a+ob2.a;
ob3.b=ob1.b+ob2.b;
return ob3;
//return 0; we need to return obj of type temo becuase we are adding to obj from temp type. also retun 0 will give an error as we have not converted the value from type temp to int.

}

int main()
{
	temp obj1, obj2, obj3;
	obj1.read();	//called using object name and dot operator (.)
	obj2.read(); 
	obj3=sumn(obj1,obj2);	 //temp is a friend function and hence we have called it with a equal to (=) operator.
	obj3.disp();
	return 0;
}

