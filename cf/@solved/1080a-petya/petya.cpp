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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    // red
    ans += int(ceil((n * 2.0) / k));
    // green
    ans += int(ceil((n * 5.0) / k));
    // blue
    ans += int(ceil((n * 8.0) / k));
    cout << ans << endl;
    return 0;
}