#include <iostream>
#include <map>
#include <string>

using namespace std;

bool c(string s) {
    if (s == "entry")
        return true;
    else if (s == "exit")
        return false;
    return false;
}

int main() {
    map<string, bool> building;
    int t;
    cin >> t;
    while (t--) {
        string command, name;
        cin >> command >> name;
        cout << name << " " << (command == "entry" ? "enter" : "exit") << "ed";
        if (building.find(name) != building.end() &&
            building[name] == c(command))
            cout << " (ANOMALY)";
        else if (building.find(name) == building.end() && !c(command))
            cout << " (ANOMALY)";
        building[name] = c(command);
        cout << endl;
    }
}
