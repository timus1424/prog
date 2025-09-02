#include<iostream>
using namespace std;

class test{
    int a,b;
    public:
    void read();
    void disp();
//    test operator+(int t1);   //when operator+ is a member function
    friend test operator+(test t1, test t2);
    friend test operator+(test t1, int);
};
void test::read(){
    cout<<"enter 2 nos. \n";
    cin>>a>>b;
}
void test::disp(){
    cout<<"A and B of the object are:";
    cout<<a<<" "<<b<<endl;
}
/*
test test::operator+(int t1)        //when operator+ is a member function
{
    test t;
    t.a=a+t1;
    t.b=b+t1;
    return t;
}
*/
test operator+(test t1, test t2)       //when operator+ is a friend function
{
    test temp;
    temp.a=t1.a+t2.a;
    temp.b=t1.b+t2.b;
    return temp;
}
test operator+(test t1, int x)       //when operator+ is a friend function
{
    test t;
    t.a=t1.a+x;
    t.b=t1.b+x;
    return t;
}

int main() {
    test t1,t2,t3,t4;
    t1.read();
    t2.read();
    t3=t1+t2;  //t3=t1.operator+(t2); //when operator+ is a member function
    //t3=operator+(t1,t2); //when operator+ is a friend function
    t4=t3+100;
    cout<<"after adding \n";
    t3.disp();
    t4.disp();
    return 0;
}
