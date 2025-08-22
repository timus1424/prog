#include<iostream>
using namespace std;

int fn(int x,float y)
//int fn(int x)
{
	return ++x;
}
int fn(int x, int y=5){
	return x+y;
}

int main(){
	int a=5, b=6;
	cout<<a<<endl<<b<<endl;
	cout<<fn(a)<<endl;
	cout<<fn(a,b)<<endl;
	cout<<fn(3,4);
	return 0;
}
