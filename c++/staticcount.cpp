#include <iostream>
using namespace std;

class XY {
    static int c;   // static data member to count objects

public:
    XY(){
	c++;
    }

    static void count() {   // static member function
        cout << "Number of objects created: " << c << endl;
    }
};

int XY::c;
//by default static variables have value as 0

int main() {
    XY ob1, ob2, ob3;
    XY::count();
//  cout<<XY::c;
    return 0;
}
