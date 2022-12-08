#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string n, p;
    bool inc = true, dec = true;
    while (t--) {
        getline(cin, n);
        if (!p.empty()) {
            if (p < n) dec = false;
            if (p > n) inc = false;
        }
        if (!inc && !dec) {
            cout << "NEITHER" << endl;
            return 0;
        }
        p = n;
    }
    if (dec) cout << "DECREASING";
    if (inc) cout << "INCREASING";
    cout << endl;
    return 0;
}
