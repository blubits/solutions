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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll even1 = 0, odd1 = 0, even2 = 0, odd2 = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 == 0) even1++;
            else odd1++;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (x % 2 == 0) even2++;
            else odd2++;
        }
        cout << even1 * even2 + odd1 * odd2 << endl;
    }
    return 0;
}