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
    ll n;
    cin >> n;
    int ans = 0;
    for (ll p = 2; p * p <= n; p++) {
        int exp = 0;
        while (n % p == 0) {
            exp++;
            n /= p;
        }
        for (int e = 1; exp - e >= 0; e++) {
            exp -= e;
            ans++;
        }
    }
    if (n > 1) ans++;
    cout << ans << endl;
    return 0;
}