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
    ll a, b, c;
    cin >> a >> b >> c;
    cout << a * b / c;
    ll res = (a * b) % c;
    if (res != 0) cout << ".";
    for (int i = 0; i < 18; i++) {
        if (res == 0) {
            break;
        }
        res *= 10;
        cout << res / c;
        res %= c;
    }
    cout << endl;
    return 0;
}