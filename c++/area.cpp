#include <iostream>
//#include <cmath>   // for sqrt
using namespace std;

// Overloaded functions
float area(float r) {      
    return 3.14f * r * r;
}

float area(float l, float b) {
    return l * b;
}

float area(float b, float h, bool isTriangle) {
    float a=0.5*b*h;
    return a;
}

int main() {
    cout << "Area of Circle (radius=5): " << area(5) << endl;
    cout << "Area of Rectangle (length=4, breadth=6): " << area(4, 6) << endl;
    cout << "Area of Triangle (base=4, height=5): " << area(4, 5, true) << endl;
    return 0;
}
