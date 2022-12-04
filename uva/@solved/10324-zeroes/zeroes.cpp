#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int c = 1;
    while (cin >> s) {
        int t, i, j;
        cout << "Case " << c++ << ":" << endl;
        cin >> t;
        while (t--) {
            cin >> i >> j;
            bool same = true;
            for (int k = min(i, j) + 1; k <= max(i, j); k++) {
                if (s[k] != s[min(i, j)]) {
                    same = false;
                    break;
                }
            }
            if (same)
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
        }
    }
    return 0;
}
