#include <iostream>

using namespace std;

int main() {
    int t, a = 0;
    cin >> t;
    while (t--) {
        double l, w, d, wt;
        cin >> l >> w >> d >> wt;
        if (((l <= 56 && w <= 45 && d <= 25) || ((l + w + d) <= 125.0)) &&
            wt <= 7.0) {
            cout << 1 << endl;
            a++;
        } else {
            cout << 0 << endl;
        }
    }
    cout << a << endl;
}
