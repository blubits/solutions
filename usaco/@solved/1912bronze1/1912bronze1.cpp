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

int lost[20][20];
int won[20][20];

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        v.clear();
        v.resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            v[j]--;
        }
        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = c1 + 1; c2 < n; c2++) {
                lost[v[c2]][v[c1]] = 1;
                won[v[c1]][v[c2]] = 1;
            }
        }
    }
    int ans = 0;
    for (int c1 = 0; c1 < n; c1++) {
        for (int c2 = 0; c2 < n; c2++) {
            if (c1 != c2 && !lost[c1][c2] && won[c1][c2]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}