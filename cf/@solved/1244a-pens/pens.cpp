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
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        bool has_soln = false;
        for (int x = 0; x <= 100 && !has_soln; x++) {
            for (int y = 0; y <= 100 && !has_soln; y++) {
                if (c * x >= a && d * y >= b && x + y <= k) {
                    has_soln = true;
                    cout << x << " " << y << endl;
                }
            }
        }
        if (!has_soln) cout << -1 << endl;
    }
    return 0;
}