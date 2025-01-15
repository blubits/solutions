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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_t = INF, min_cost = INF;
    for (int t = 1; t <= 100; t++) {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            int c1 = abs(a[i] - t);
            int c2 = abs(a[i] - (t + 1));
            int c3 = abs(a[i] - (t - 1));
            cost += min(c1, min(c2, c3));
        }
        if (cost < min_cost) {
            min_cost = cost;
            min_t = t;
        }
    }
    cout << min_t << " " << min_cost << endl;
    return 0;
}