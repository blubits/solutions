#include <iostream>
#include <string>

using namespace std;

int main() {
    string moveset;
    cin >> moveset;
    for (int i = 0; i < moveset.size(); i++) {
        string ss = moveset.substr(i, 3);
        if (ss == "BLR" || ss == "BRL" || ss == "LBR" || ss == "LRB" ||
            ss == "RBL" || ss == "RLB") {
            cout << "C";
            i += 2;
        } else if (moveset[i] == 'R') {
            cout << "S";
        } else if (moveset[i] == 'B') {
            cout << "K";
        } else if (moveset[i] == 'L') {
            cout << "H";
        }
    }
    cout << endl;
}
