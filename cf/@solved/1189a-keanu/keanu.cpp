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
    int o = 0, z = 0;
    for (auto &c: s) {
        if (c == '0') o++;
        else z++;
    }
    if (o != z) cout << 1 << endl << s << endl;
    else {
        cout << 2 << endl << s[0] << " " << s.substr(1) << endl;
    }
    return 0;
}