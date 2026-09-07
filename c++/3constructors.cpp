#include <iostream>
using namespace std;

class Demo {
public:
    Demo(int x) {
        cout << "Constructor called with: " << x << endl;
    }
};

int main() {
    Demo a(10);          // 1. direct initialization
    Demo b = Demo(20);   // 2. copy initialization
    Demo *c = new Demo(30); // 3. dynamic initialization

    delete c;
    return 0;
}

