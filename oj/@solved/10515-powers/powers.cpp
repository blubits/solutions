#include <iostream>
#include <string>

using namespace std;

int main() {
    string m, n;
    while (cin >> m >> n && !(m == "0" && n == "0")) {
        char lm = m[m.length() - 1];

        // check exp for 0
        if (n == "0") cout << 1 << endl;

        // check trivial LMs: 0, 1, 5, 6
        else if (lm == '1' || lm == '5' || lm == '6' || lm == '0')
            cout << lm << endl;

        // everything else appears in a cycle
        // lm       ^4n     ^4n+1       ^4n + 2     ^4n + 3
        // 2        6       2           4           8
        // 3        1       3           9           7
        // 4        6       4           6           4
        // 7        1       7           9           3
        // 8        6       8           4           2
        // 9        1       9           1           9
        // get the last two digits of n and stoi it
        else {
            string lns;
            if (n.length() == 1)
                lns = n[n.length() - 1];
            else {
                lns = n[n.length() - 2];
                lns += n[n.length() - 1];
            }
            int ln = stoi(lns);
            if (ln % 4 == 0) {
                if (lm == '2' || lm == '4' || lm == '8') cout << 6 << endl;
                if (lm == '3' || lm == '7' || lm == '9') cout << 1 << endl;
            } else if (ln % 4 == 1) {
                cout << lm << endl;
            } else if (ln % 4 == 2) {
                int mm = lm - '0';
                cout << (mm * mm) % 10 << endl;
            } else if (ln % 4 == 3) {
                int mm = lm - '0';
                cout << (mm * mm * mm) % 10 << endl;
            }
        }
    }
    return 0;
}
