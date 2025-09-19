#include <iostream>
using namespace std;

class Person {
    string name;
    int age;
    string country;
public:
    Person() {
        name = "Mukesh Ambani";
        age = 72;
        country = "India";
    }
    Person(string n, int a, string c) {
        name = n;
        age = a;
        country = c;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age
             << ", Country: " << country << endl;
    }
};

int main() {
    // Using default constructor
    Person p1;
    p1.display();

    // Using parameterized constructor
    Person p2("Eemon Mukherjee", 99, "USA");
    p2.display();

    return 0;
}
