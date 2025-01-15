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
    int n, k;
    cin >> n >> k;
    vi tabs(n);
    int sum_without_mod[k] = {0};
    for (int i = 0; i < n; i++) {
        cin >> tabs[i];
        for (int j = 0; j < k; j++) {
            if (j != i % k) sum_without_mod[j] += tabs[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = max(ans, abs(sum_without_mod[i]));
    }
    cout << ans << endl;
    return 0;
}