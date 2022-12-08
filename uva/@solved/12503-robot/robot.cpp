#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        int inst[c];
        int pos = 0, idx;
        string s;
        for (int i = 0; i < c; i++) {
            cin >> s;
            if (s == "LEFT") {
                inst[i] = -1;
                pos -= 1;
            } else if (s == "RIGHT") {
                inst[i] = 1;
                pos += 1;
            } else {
                cin >> s >> idx;
                idx -= 1;
                inst[i] = inst[idx];
                pos += inst[idx];
            }
        }
        cout << pos << endl;
    }
    return 0;
}
