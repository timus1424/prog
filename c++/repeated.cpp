#include <iostream>
using namespace std;

class STACK {
    int top, arr[50];
public:
    STACK() { top = -1; }

    // ++ operator → push element
    STACK operator+(int e) {
        if (top == 49) 
            cout << "Stack Full\n";
        else 
            arr[++top] = e;
        return *this;
    }

    // -- operator → pop element
    STACK operator--(int) {
        if (top == -1) {
            cout << "Stack Empty\n";
        } else {
            cout << "Popped: " << arr[top--] << endl;
        }
        return *this;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    STACK s1;
    s1=s1+10;   // push
    s1=s1+20;
    s1=s1+30;
    s1.display();
    s1--;   // pop
    s1.display();
}