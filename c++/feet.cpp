#include <iostream>
using namespace std;

class Distance {
    int feet, inches;

public:
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }
    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
    friend void ADD(Distance &d, int n);
};

void ADD(Distance &d,int n) {
    d.inches += n;             // add 10 inches
    d.feet += d.inches / 12;    // carry over to feet if >= 12
    d.inches = d.inches % 12;   // keep remainder in inches
}

int main() {
    Distance d1(5, 8);
    int n; 
    cout<<"Enter distance to be added in inches: ";
    cin>>n;
    cout << "Original Distance: ";
    d1.display();

    ADD(d1, n);  // add n inches

    cout << "Modified Distance:";
    d1.display();

    return 0;
}
