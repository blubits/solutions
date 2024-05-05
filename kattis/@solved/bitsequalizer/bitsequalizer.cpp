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
    int T, cs = 1;
    cin >> T;
    while (T--) {
        string u, v;
        cin >> u >> v;
        int b = 0, c = 0, e = 0, f = 0;
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '0' && v[i] == '1') b++;
            if (u[i] == '1' && v[i] == '0') c++;
            if (u[i] == '?' && v[i] == '0') e++;
            if (u[i] == '?' && v[i] == '1') f++;
        }
        int ans = 0;
        int x = min(b, c);
        ans += x;
        b -= x;
        c -= x;
        if (b > 0) {
            ans += b + e + f;
        } else {
            if (f < c) {
                ans = -1;
            } else {
                ans += c;
                f -= c;
                ans += c;
                ans += e + f;
            }
        }
        cout << "Case " << cs++ << ": " << ans << endl;
    }
    return 0;
}