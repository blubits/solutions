#include <iostream>
using namespace std;

int main() {
    bool submitted[100][15] = {};
    int last_time_submitted[15] = {};
    int last_team_submitted[15] = {};
    int problems, teams, submissions;
    cin >> problems >> teams >> submissions;
    while (submissions--) {
        int t, team_id;
        char problem_id;
        string verdict;
        cin >> t >> team_id >> problem_id >> verdict;
        if (verdict == "Yes") {
            if (!submitted[team_id][int(problem_id - 'A')]) {
                submitted[team_id][int(problem_id - 'A')] = true;
                last_time_submitted[int(problem_id - 'A')] = t;
                last_team_submitted[int(problem_id - 'A')] = team_id;
            }
        }
    }
    for (int i = 0; i < problems; i++) {
        cout << char('A' + i) << " ";
        if (last_time_submitted[i] == 0 && last_team_submitted[i] == 0)
            cout << "- -" << endl;
        else
            cout << last_time_submitted[i] << " " << last_team_submitted[i]
                 << endl;
    }
}
