#include <iostream>
#include <string>
using namespace std;

class Cricket {
    string playerName;
    string teamName;
    float battingAverage;

public:
    void readData() {
        cout << "Enter player name: ";
        getline(cin, playerName);
        cout << "Enter team name: ";
        getline(cin, teamName);
        cout << "Enter batting average: ";
        cin >> battingAverage;
        cin.ignore();
    }

    void displayData() const {
        cout << "   - " << playerName
             << " (Average: " << battingAverage << ")\n";
    }

    string getTeamName() const {
        return teamName;
    }
};

int main() {
    int n;
    cout << "Enter number of players: ";
    cin >> n;
    cin.ignore();

    Cricket players[50];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Player " << i + 1 << " ---\n";
        players[i].readData();
    }

    string searchTeam;
    cout << "\nEnter team name to display its players: ";
    getline(cin, searchTeam);

    cout << "\nTeam: " << searchTeam << "\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (players[i].getTeamName() == searchTeam) {
            players[i].displayData();
            found = true;
        }
    }

    if (!found) {
        cout << "No players found for this team.\n";
    }

    return 0;
}
