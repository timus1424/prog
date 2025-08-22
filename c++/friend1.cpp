#include <iostream>
using namespace std;
class temp
{
    int a,b;
public:
    void read( );
    void disp( );
    //friend void read(temp ob );
    //friend void disp(temp ob );
};
temp obj; //global object
void temp::read( )
// void read(temp ob)
    {
        cout<<"Enter 2 nos \n";
        cin>>a>>b;
    }
void temp::disp ( )
//void disp(temp ob)
    {
        cout<<"Object has:\n";
        cout<<a<<endl;
        cout<<b<<endl;
    }
int main()
{
//    temp obj;
    obj.read( );
    obj.disp( );
    return 0;
}
