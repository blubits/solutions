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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n), s(n), c(k);
    map<int, int> max_power;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        max_power[s[i]] = max(max_power[s[i]], p[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> c[i];
        if (p[c[i] - 1] != max_power[s[c[i] - 1]]) ans++;
    }
    cout << ans << endl;
    return 0;
}