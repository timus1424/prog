#include <iostream>
using namespace std;

class MATRIX {
public:
    int r, c, i,j;
    int mat[5][5];
    void read() {
        cout << "Enter rows and columns: ";
        cin >> r >> c;
        cout <<"\nEnter elements:\n";
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                cin >> mat[i][j];
    }
    void display() {
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    bool operator==(MATRIX m) {
        return (r == m.r && c == m.c);
    }
    MATRIX operator+(MATRIX m) {
        MATRIX temp;
        temp.r = r; temp.c = c;
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
        return temp;
    }
    MATRIX operator-(MATRIX m) {
        MATRIX temp;
        temp.r = r; temp.c = c;
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                temp.mat[i][j] = mat[i][j] - m.mat[i][j];
        return temp;
    }
};

int main() {
    MATRIX m1, m2, m3,m4;
    m1.read();
    m2.read();
    if (m1 == m2) {
        cout <<"Addition:\n";
        m3 = m1 + m2;
        m3.display();
        cout <<"Subtraction:\n";
        m4 = m1 - m2;
        m4.display();
    } 
    else 
        cout << "Matrices not compatible!\n";
    return 0;
}
