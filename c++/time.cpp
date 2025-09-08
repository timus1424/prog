// Usage to overload + operator to add time:

#include <iostream>
using namespace std;

class time1 {
    int hr, min;
public:
    void read() {
        cout << "Enter Time in Hrs. and Mins.: \n";
        cin >> hr >> min;
    }

    time1 operator+(time1 x);
    
    void disp() {
        cout << "Computed Time is: " << hr << " hrs " << min << " mins" << endl;
    }
};

// Operator+ definition
time1 time1::operator+(time1 x) {
    time1 temp;
    temp.hr = hr + x.hr;
    temp.min = min + x.min;

    // normalize minutes
    temp.hr += temp.min / 60;
    temp.min = temp.min % 60;

    return temp;
}

int main() {
    time1 t1, t2, t3;
    t1.read();
    t2.read();
    t3 = t1 + t2;
    t3.disp();
    return 0;
}
