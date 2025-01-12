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
    vi guards(n);
    for (int i = 0; i < n; i++) {
        cin >> guards[i];
    }
    sort(guards.begin(), guards.end());
    int ans = 0;
    int max_guard = *max_element(guards.begin(), guards.end());
    int min_guard = *min_element(guards.begin(), guards.end());
    for (int i = 0; i < n; i++) {
        if (guards[i] != min_guard && guards[i] != max_guard) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}