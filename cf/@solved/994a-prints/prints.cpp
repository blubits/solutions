#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

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
    int n, m;
    cin >> n >> m;
    vector<int> seq(n);
    vector<bool> has_fingerprint(10);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        has_fingerprint[k] = true;
    }
    for (auto c: seq) {
        if (has_fingerprint[c]) cout << c << " ";
    }
    cout << endl;
    return 0;
}