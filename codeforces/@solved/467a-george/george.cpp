#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int ans = 0;
    while (T--) {
        int p, q;
        cin >> p >> q;
        if (q - p >= 2) ans++;
    }
    cout << ans << endl;
    return 0;
}
