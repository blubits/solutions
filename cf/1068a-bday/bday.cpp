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
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    ll ans = (l + k) / m + ((l + k) % m != 0);
    if (ans * m > n) cout << -1;
    else cout << ans;
    cout << endl;
    return 0;
}