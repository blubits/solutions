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
    int n, a, b;
    cin >> n >> a >> b;
    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
        if (arr[l] == 2 && arr[r] == 2) {
            ans += 2 * min(a, b);
        }
        if (arr[l] != arr[r]) {
            if (arr[l] == 2) {
                ans += (arr[r] == 0) ? a : b;
            } else if (arr[r] == 2) {
                ans += (arr[l] == 0) ? a : b;
            } else {
                ans = -1;
                break;
            }
        } 
        l++;
        r--;
    }
    if (l == r && arr[l] == 2) ans += min(a, b);
    cout << ans << endl;
    return 0;
}