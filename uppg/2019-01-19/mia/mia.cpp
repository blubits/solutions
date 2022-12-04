#include <iostream>

using namespace std;

int value(int d1, int d2) {
    int d;
    if (d1 > d2)
        d = (d1 * 10) + d2;
    else
        d = (d2 * 10) + d1;
    if (d == 21)
        return 10000;
    else if (d % 11 == 0)
        return d * 100;
    else
        return d;
}
int main() {
    int s0, s1, r0, r1;
    while (cin >> s0 >> s1 >> r0 >> r1 && (s0 || s1 || r0 || r1)) {
        int vs = value(s0, s1), vr = value(r0, r1);
        if (vs > vr) {
            cout << "Player 1 wins." << endl;
        } else if (vr > vs) {
            cout << "Player 2 wins." << endl;
        } else {
            cout << "Tie." << endl;
        }
    }
}
