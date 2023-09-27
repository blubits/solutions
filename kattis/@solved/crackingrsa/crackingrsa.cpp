#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int T, n, e;
    cin >> T;
    while (T--) {
        cin >> n >> e;
        int p, q;
        for (int i = 2; i <= 1000; i++) {
            if (n % i == 0) {
                p = i;
                q = n / i;
                break;
            }
        }
        ll tot = (p - 1) * (q - 1);
        for (ll d = 1; d <= tot; d++) {
            ll product = d * e - 1;
            if (product % tot == 0) {
                cout << d << endl;
                break;
            }
        }
    }
    return 0;
}