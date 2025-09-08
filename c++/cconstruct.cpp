#include<iostream>
using namespace std;

class test{
	int *ptr, sz;
	public:
	test(int s)
	{
		sz=s;
		ptr=new int[s];
	}
	test(const test &0)
	{
		sz=0.sz;
		ptr=new int[sz];
	}
	void read(){
		for(int i=0;i<sz;i++)
			cin>>*(ptr+i);
	}
	void disp(){
		for(int i=0;i<sz;i++)
			cout<<*(ptr+i)<<endl;
	}
};

int main()
{
	test t1(2),t2(2);
	t1.read();
	t2=t1;
	t2.disp();
	t1.read();
	t2.disp();
	return 0;
}
