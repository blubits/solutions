#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;
        int max_t = 0, min_t = 0;
        while (n--) {
            int ai;
            cin >> ai;
            max_t = max(max_t, max(ai, l - ai));
            min_t = max(min_t, min(ai, l - ai));
        }
        cout << min_t << " " << max_t << endl;
    }
}
