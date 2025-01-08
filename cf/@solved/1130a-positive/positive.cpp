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
    int p = 0, z = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k > 0) p++;
        else if (k < 0) m++;
        else z++;
    }
    int target = n % 2 == 0 ? n / 2 : n / 2 + 1;
    if (p >= target) cout << 1;
    else if (m >= target) cout << -1;
    else cout << 0;
    cout << endl;
    return 0;
}