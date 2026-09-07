#include<iostream>
using namespace std;

class circle{
    int rad;
    const float pi=3.14;
    float area;
    public:
    void read(){
        cout<<"Enter radius of circle: ";
        cin>>rad;
    }
    void calc(){
        area=pi*rad*rad;
    }
    void disp(){
        cout<<"Area of Circle of radius "<<rad<<" is: "<<area<<endl;
    }
};

int main(){
    circle c;
    c.read();
    c.calc();
    c.disp();
    return 0;
}
