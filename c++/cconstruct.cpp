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
	test(const test &x)
	{
		sz=x.sz;
		ptr=new int[x.sz];
	}
	void read(){
		for(int i=0;i<sz;i++)
			cin>>*(ptr+i);
	}
	void disp(){
		for(int i=0;i<sz;i++)
			cout<<*(ptr+i)<<endl;
	}
	void xyz(){
		cout<<ptr<<endl;	//ptr:0x600001230030 \n 0x600001230040 \n 0x600001230050;	sz:2
	}
};

int main()
{
	test t1(2),t2=t1,t3=t1; //t2(t1),t3(2);
//	t2=t1;
//	t3=t1;
//	t1.disp();
//	t2=t1;
//	t2.disp();
//	t1.read();
//	t3.disp();

	t1.xyz();
	t2.xyz();
	t3.xyz();
	return 0;
}
