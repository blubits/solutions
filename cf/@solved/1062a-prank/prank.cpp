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
    vector<bool> a(1001);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = true;
    }
    // Find the size of contiguous elements.
    int ans = 0;
    int curr_size = 0;
    bool is_start = true;
    for (int i = 1; i < 1001; i++) {
        if (a[i]) {
            curr_size++;
        } else {
            ans = max(ans, max(0, curr_size - (is_start ? 1 : 2)));
            is_start = false;
            curr_size = 0;
        }
    }
    ans = max(ans, max(0, curr_size - 1));
    cout << ans << endl;
    return 0;
}