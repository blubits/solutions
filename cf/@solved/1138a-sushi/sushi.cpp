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
    int curr_type = a[0];
    int curr_count = 1;
    int prev_type = a[0] == 1 ? 2 : 1;
    int prev_count = 0;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != curr_type) {
            ans = max(ans, min(curr_count, prev_count));
            prev_type = curr_type;
            prev_count = curr_count;
            curr_type = a[i];
            curr_count = 1;
        } else {
            curr_count++;
        }

    }
    ans = max(ans, min(curr_count, prev_count));
    cout << ans * 2 << endl;
    return 0;
}