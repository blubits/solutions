#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    while (k--) {
        int m = 0, f = 0;
        do {
            string s;
            cin >> s;
            for (char c : s) {
                if (c == 'M')
                    m++;
                else if (c == 'F')
                    f++;
            }
        } while (cin.peek() != '\n');
        if (m == f && m > 1 && f > 1)
            cout << "LOOP" << endl;
        else
            cout << "NO LOOP" << endl;
    }
    return 0;
}
