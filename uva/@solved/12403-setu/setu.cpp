#include <iostream>
#include <string>

using namespace std;

int main() {
    int t, bal = 0, dep;
    string c;
    cin >> t;
    while (t--) {
        cin >> c;
        if (c == "donate") {
            cin >> dep;
            bal += dep;
        } else if (c == "report") {
            cout << bal << endl;
        }
    }
    return 0;
}
