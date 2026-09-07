#include<iostream>
using namespace std;

class A{
public:
int a;
};

class B:public A
{
};

class C:public A
{ 
};

class D:public B,public C
{ 
};

int main(){
D obj;
obj.a=5;	//obj.B::a;	obj.c::a;
cout<<obj.a;
return 0;
}
