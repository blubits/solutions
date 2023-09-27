#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> bitmasks;
    int N, M, ans;
    cin >> N >> M;
    ans = 1 << N;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        bitmasks.push_back((1 << a) | (1 << b));
    }
    for (int mask = 0; mask < 1 << N; mask++) {
        for (auto m: bitmasks) {
            if ((mask | m) == mask) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}