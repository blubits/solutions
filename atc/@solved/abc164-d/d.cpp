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
    string s;
    cin >> s;
    int num = 0, pow = 1;
    ll count[2019] = {};
    for (int i = s.size() - 1; i >= 0; i--) {
        num += pow * (s[i] - '0');
        num %= 2019;
        count[num]++;
        pow *= 10;
        pow %= 2019;
    }
    ll ans = count[0];
    for (int i = 0; i < 2019; i++) {
        if (count[i] >= 2) {
            ans += count[i] * (count[i] - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}