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
    ll n, x, y;
    cin >> n >> x >> y;
    ll white = max(x - 1, y - 1);
    ll black = max(n - x, n - y);
    if (white > black) cout << "Black" << endl;
    else cout << "White" << endl;
    return 0;
}