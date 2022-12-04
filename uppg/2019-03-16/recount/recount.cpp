#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> votes;
    string name;
    while (getline(cin, name) && name != "***") {
        if (votes.find(name) == votes.end())
            votes[name] = 1;
        else
            votes[name]++;
    }
    int max_votes = 0, max_count = 1;
    string max_name;
    for (auto p : votes) {
        if (p.second > max_votes) {
            max_votes = p.second;
            max_name = p.first;
            max_count = 1;
        } else if (p.second == max_votes) {
            max_count++;
        }
    }
    if (max_count != 1)
        cout << "Runoff!" << endl;
    else
        cout << max_name << endl;
}
