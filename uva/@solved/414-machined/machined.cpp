#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    while (cin >> t && t != 0) {
        cin.ignore();
        int b[t];
        string s;
        for (int i = 0; i < t; i++) {
            getline(cin, s);
            int spaces = 0;
            for (auto c : s) {
                if (c == ' ') spaces++;
            }
            b[i] = spaces;
        }
        // find min
        int min = 10000000;
        for (int i = 0; i < t; i++) {
            if (min > b[i]) min = b[i];
        }
        // get i - min
        int ans = 0;
        for (int i = 0; i < t; i++) {
            ans += b[i] - min;
        }
        cout << ans << endl;
    }
}
