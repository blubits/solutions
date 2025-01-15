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
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    a--; x--; b--; y--;
    while (a != x && b != y) {
        if (a != x) a = (a + 1) % n;
        if (b != y) b = (b + n - 1) % n;
        if (a == b) break;
    }
    if (a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}