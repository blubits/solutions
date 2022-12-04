#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        bool present[n];
        for (int i = 0; i < n; i++) present[i] = false;
        int a, b;
        cin >> a;
        for (int i = 1; i < n; i++) {
            cin >> b;
            if (abs(a - b) < n) present[abs(a - b)] = true;
            a = b;
        }
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            if (!present[i]) {
                jolly = false;
                break;
            }
        }
        if (jolly)
            cout << "Jolly";
        else
            cout << "Not jolly";
        cout << endl;
    }
}
