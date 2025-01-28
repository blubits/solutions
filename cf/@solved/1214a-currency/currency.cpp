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
    int n, e, d;
    cin >> n >> d >> e;
    int ans = INF;
    for (int e5 = 0; e5 <= n; e5 += 5 * e) {
        ans = min(ans, (n - e5) % d);
    }
    cout << ans << endl;
    return 0;
}