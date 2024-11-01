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

int main() {
    int n;
    cin >> n;
    vector<int> last_page(n);
    for (int i = 0; i < n; i++) {
        int _;
        cin >> _ >> last_page[i];
    }
    int k, ans = n;
    cin >> k;
    for (int i = 0; i < n; i++) {
        if (last_page[i] < k) ans--;
        else break;
    }
    cout << ans << endl;
    return 0;
}