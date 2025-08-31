#include<iostream>
using namespace std;

class example{
    int a,b;
    public:
    void read(){
	cin>>a>>b;	
    }
    void disp(){
	cout<<a<<endl<<b<<endl;
    }
    example operator+(example x)
    {
        example e;
        e.a=a+x.a;
//	e.a=this->a-x.a;
        e.b=b+x.b;
        return e;
    }
    example operator-(example y) //(int t)
    {
	example e;  
	e.a=a-y.a;	//e.a=a-t;
	e.b=b-y.b;
	return e;
    }
};

int main() {
    example e1,e2,e3,e4;
    e1.read();
    e2.read();
//    e3=e1.operator+(e2);
    e3=e2+e1;
    e4=e2-e1;	//e4=e2-1;
    e3.disp();
    e4.disp();	//3 4 will display 2 3
    return 0;
}
