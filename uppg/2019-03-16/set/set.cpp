#include <iostream>
#include <string>

using namespace std;

bool settable(string &a, string &b, string c) {
    for (int i = 0; i < 4; i++) {
        if (!((a[i] == b[i] && a[i] == c[i] && b[i] == c[i]) ||
              (a[i] != b[i] && a[i] != c[i] && b[i] != c[i])))
            return false;
    }
    return true;
}
int main() {
    string cards[12];
    bool sets = false;
    for (int i = 0; i < 12; i++) cin >> cards[i];
    for (int a = 0; a < 12; a++) {
        for (int b = a + 1; b < 12; b++) {
            for (int c = b + 1; c < 12; c++) {
                if (settable(cards[a], cards[b], cards[c])) {
                    sets = true;
                    cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
                }
            }
        }
    }
    if (!sets) cout << "no sets" << endl;
}
