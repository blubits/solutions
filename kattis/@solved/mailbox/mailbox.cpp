#include <algorithm>
#include <iostream>
using namespace std;

int fcneeded[11][110][110];

int dp(int k, int l, int r) {
    if (l > r) return 0;
    if (k == 1) return (r * (r + 1)) / 2 - ((l) * (l - 1)) / 2;
    int &ret = fcneeded[k][l][r];
    if (ret != -1) {
        // cout << "cached " << k << " " << l << " " << r << endl;
        return ret;
    }
    ret = 1 << 30;
    for (int i = l; i <= r; i++) {
        ret = min(ret, i + max(dp(k - 1, l, i - 1), dp(k, i + 1, r)));
    }
    return ret;
}

int main() {
    for (int k = 0; k < 11; k++) {
        for (int l = 0; l < 110; l++) {
            for (int r = 0; r < 110; r++) {
                fcneeded[k][l][r] = -1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int m, k;
        cin >> k >> m;
        cout << dp(k, 1, m) << endl;
    }
}
