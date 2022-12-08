#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0)) {
        int ans = 0, an = 0, bn = 0, cn = 0;
        while (a != 0 || b != 0) {
            an = a % 10;
            bn = b % 10;
            cn += an + bn;
            if (cn / 10 != 0) ans++;
            a /= 10;
            b /= 10;
            cn /= 10;
        }
        if (ans == 0) {
            cout << "No carry operation." << endl;
        } else if (ans == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << ans << " carry operations." << endl;
        }
    }
}
