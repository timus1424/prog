#include <iostream>
using namespace std;

class Complex {
    float real, imag;  // real and imaginary parts
public:
    void read() {
        cout << "Enter real and imaginary parts: ";
        cin >> real >> imag;
    }
    void disp() {
        cout << real << " + " << imag << "i" << endl;
    }
    friend Complex operator+(Complex c1, Complex c2);
    friend Complex operator-(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}
Complex operator-(Complex c1, Complex c2) {
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}

int main() {
    Complex c1, c2, sum, diff;
    c1.read();
    c2.read();
    sum = c1 + c2;   // using overloaded operator
    diff = c1 - c2;  // using overloaded operator
    cout << "Sum:";
    sum.disp();
    cout<<"Difference:";
    diff.disp();
    return 0;
}