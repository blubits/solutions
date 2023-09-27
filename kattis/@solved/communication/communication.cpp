#include <bits/stdc++.h>
using namespace std;

int main() {
    int unscrambled[300];
    for (int i = 0; i <= 255; i++) {
        unscrambled[(i ^ (i << 1)) & ((1 << 8) - 1)] = i;
    }
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        cout << unscrambled[x];
        if (T) cout << " ";
    }
    cout << endl;
    return 0;
}