#include <iostream>
using namespace std;

class Matrix {
    int mat[10][10];
    int r, c;
public:
    void read() {
        cout << "Enter rows and columns: ";
        cin >> r >> c;
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> mat[i][j];
    }
    void display() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }
    Matrix operator+(Matrix M) {
        Matrix temp;
        temp.r = r;
        temp.c = c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                temp.mat[i][j] = mat[i][j] + M.mat[i][j];
        return temp;
    }
};

int main() {
    Matrix m1, m2, m3;
    cout << "Enter first matrix:\n";
    m1.read();
    cout << "Enter second matrix:\n";
    m2.read();
    m3 = m1 + m2;
    cout << "\nResultant Matrix:\n";
    m3.display();
    return 0;
}
