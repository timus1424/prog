#include <iostream>
using namespace std;

class Box {
    int l, w, h;
public:
    void read() {
        cout << "Enter l, w, h: ";
        cin >> l >> w >> h;
    }
    int volume() { return l * w * h; }

    bool operator>(Box b) { return volume() > b.volume(); }
    bool operator<(Box b) { return volume() < b.volume(); }
    bool operator==(Box b) { return volume() == b.volume(); }
};

int main() {
    Box b1, b2; //b3;
    b1.read(); b2.read(); //b3.read();

    if (b1 > b2) cout << "Box1 is greater\n";
    else if (b1 < b2) cout << "Box1 is smaller\n";
    else cout << "Box1 and Box2 are equal\n";
    return 0;
}
