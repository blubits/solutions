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
    ll a, b;
    cin >> a >> b;
    ll x = a ^ b;
    ll msb = 0;
    while (x > 0) {
        x >>= 1;
        msb++;
    }
    ll ans = (1LL << msb) - 1;
    cout << ans << endl;
    return 0;
}