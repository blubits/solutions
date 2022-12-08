#include <iostream>

using namespace std;

int main() {
    int t, max = 0;
    cin >> t;
    int a[t];
    for (int i = 0; i < t; i++) {
        cin >> a[i];
        if (a[i] > max) max = a[i];
    }
    int ans = 0;
    for (int i = 0; i < t; i++) {
        ans += max - a[i];
    }
    cout << ans << endl;
    return 0;
}
