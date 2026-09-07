#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    float salary;
public:
    Employee(string n, float s) {
        name = n;
        salary = s;
    }
    virtual void display_info() {
        cout << "Name: " << name << "\nSalary: " << salary << endl;
    }
};

class Manager : public Employee {
    string department;
public:
    Manager(string n, float s, string d) : Employee(n, s) {
        department = d;
    }
    virtual void display_info(){// override {
        cout << "Name: " << name 
             << "\nSalary: " << salary
             << "\nDepartment: " << department << endl;
    }
};

int main() {
    //Employee e("Amit", 300000);
    Manager m("Rita", 500000, "PR");
    Employee e("Amit", 300001);
    e.display_info();
    m.display_info();
    return 0;
}
