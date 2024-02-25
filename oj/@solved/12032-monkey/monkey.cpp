#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<int> rungs;

bool jumpable(int k) {
    int curr = 0;
    for (auto rung: rungs) {
        int jump = rung - curr;
        if (jump > k) return false;
        if (jump == k) k--;
        curr = rung;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        rungs.clear();
        int n;
        cin >> n;
        rungs.resize(n);
        for (int i = 0; i < n; i++) cin >> rungs[i];
        int lo = 0, hi = 10000000, mid = 0;
        for (int i = 0; i < 40; i++) {
            mid = lo + (hi - lo) / 2;
            if (jumpable(mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        printf("Case %d: %d\n", t + 1, mid);
    }
    return 0;
}