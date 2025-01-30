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
    string s;
    cin >> s;
    string alt1, alt2;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            alt2 += s[i];
        } else {
            alt1 += s[i];
        }
    }
    if (n % 2 == 0) {
        reverse(alt1.begin(), alt1.end());
        cout << alt1 << alt2 << endl;
    } else {
        reverse(alt2.begin(), alt2.end());
        cout << alt2 << alt1 << endl;
    }

    return 0;
}