/* Write a program in C++ to create a class name, cricket with the following 
details, player name, team name players batting average using the class 
cricket declared an area of elements and read information about all the 
players and further desplay teamwise list containing names of players with 
average batting score.
*/


#include <iostream>
#include <string>
using namespace std;

class cricket {
    string p_name;
    string t_name;
    float batting_avg;

public:
    void read() {
        cout << "Enter player name: ";
        getline(cin, p_name);
        cout << "Enter team name: ";
        getline(cin, t_name);
        cout << "Enter batting average: ";
        cin >> batting_avg;
        cin.ignore();
    }

    void disp() const {
        cout << "Player: " << p_name
             << " | Team: " << t_name
             << " | Average: " << batting_avg << endl;
    }

    string get_t_name() const {
        return t_name;
    }
};

void sort(cricket players[], int n) {
	int i, j;
    	for (i = 0; i < n - 1; i++) {
        	for (j = 0; j < n - i - 1; j++) {
            		if (players[j].get_t_name() > players[j + 1].get_t_name()) {
		                cricket temp = players[j];
                		players[j] = players[j + 1];
                		players[j + 1] = temp;
           		}
        	}
    	}
}

int main() {
    int n,i;
    cout << "Enter number of players: ";
    cin >> n;
    cin.ignore();

    cricket players[10];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Player " << i + 1 << " ---\n";
        players[i].read();
    }

    sort(players, n);

    cout << "\nTeamwise Player List: \n";
    for (i = 0; i < n; i++) {
        players[i].disp();
    }

    return 0;
}
