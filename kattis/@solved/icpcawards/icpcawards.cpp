#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> unis;
    map<string, string> teams;
    while (t--) {
        string uni, team;
        cin >> uni >> team;
        if (teams.find(uni) == teams.end()) {
            unis.push_back(uni);
            teams[uni] = team;
        }
    }
    for (int i = 0; i < 12; i++) {
        cout << unis[i] << " " << teams[unis[i]] << endl;
    }
    return 0;
}
