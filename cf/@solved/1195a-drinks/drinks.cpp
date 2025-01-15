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
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    int ans = 0;
    int odds = 0;
    for (auto &[d, cnt] : freq) {
        ans += (cnt / 2) * 2;
        odds += cnt % 2;
    }
    ans += ceil(odds / 2.0);
    cout << ans << endl;
    return 0;
}