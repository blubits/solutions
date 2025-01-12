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
    vi houses(n);
    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }
    int min_dist = INF;
    for (int i = 0; i < n; i++) {
        if (houses[i] != 0 && houses[i] <= k) {
            // I can buy this house
            min_dist = min(min_dist, abs(m - i - 1));
        }
    }
    cout << min_dist * 10 << endl;
    return 0;
}