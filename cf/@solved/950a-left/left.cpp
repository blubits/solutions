#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int l, r, a;
    cin >> l >> r >> a;
    // Step 1: Equalize the teams.
    int diff = abs(l - r);
    if (l > r) {
        r += min(diff, a);
        a -= min(diff, a);
    } else {
        l += min(diff, a);
        a -= min(diff, a);
    }
    // Step 2: Distribute the rest.
    l += (a / 2);
    r += (a / 2);
    cout << min(l, r) * 2 << endl;
    return 0;
}