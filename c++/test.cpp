#include<iostream>
using namespace std;

class test{
    int a,b;
    public:
    void read();
    void disp();
    test operator+(test x);
};
void test::read(){
    cout<<"enter 2 nos. \n";
    cin>>a>>b;
}
void test::disp(){
    cout<<"A and B of the object are:";
    cout<<a<<" "<<b<<endl;
}
test test::operator+(test t1)
{
    test t;
    t.a=a+t1.a;
    t.b=b+t1.b;
    return t;
}

int main() {
    test t1,t2,t3;
    t1.read();
    t2.read();
    t3=t1+t2;  //t3=t1.operator+(t2);
    t3.disp();
    return 0;
}
