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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < m; i++) {
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        l--; r--;
        for (int j = l; j <= r; j++) {
            if (s[j] == c1) s[j] = c2;
        }
    }
    cout << s << endl;
    return 0;
}