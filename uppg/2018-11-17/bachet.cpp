#include <iostream>

using namespace std;

int main() {
    int k, n;
    while (cin >> k >> n) {
        // input
        int m[n];
        int a[k + 1];
        for (int i = 0; i < n; i++) cin >> m[i];
        // init
        a[0] = 0;
        // algo
        for (int i = 1; i <= k; i++) {
            a[i] = 0;
            for (auto x : m) {
                if (x <= i) {
                    if (!a[i - x]) {
                        a[i] = 1;
                        break;
                    }
                }
            }
        }
        if (a[k]) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }
}
