#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

const int MOD = 1000000000;

map<int, int> pfA, pfB;

int main() {
    int N, M;
    cin >> N;
    while (N--) {
        int a;
        cin >> a;
        for (int p = 2; p * p <= a; p++) {
            while (a % p == 0) {
                a /= p;
                pfA[p]++;
            }
        }
        if (a > 1) pfA[a]++;
    }
    cin >> M;
    while (M--) {
        int b;
        cin >> b;
        for (int p = 2; p * p <= b; p++) {
            while (b % p == 0) {
                b /= p;
                pfB[p]++;
            }
        }
        if (b > 1) pfB[b]++;
    }
    // cout << "A: ";
    // for (auto &[a, b]: pfA) cout << a << "x" << b << ", ";
    // cout << endl;
    // cout << "B: ";
    // for (auto &[a, b]: pfB) cout << a << "x" << b << ", ";
    // cout << endl;

    ll ans = 1;
    bool greater_than_1B = false;
    for (auto &[pf, ct]: pfA) {
        if (pfB.count(pf)) {
            int minct = min(ct, pfB[pf]);
            for (int i = 0; i < minct; i++) {
                ans *= pf;
                if (ans >= 1000000000) {
                    ans %= MOD;
                    greater_than_1B = true;
                }
            }
        }
    } 

    if (greater_than_1B) printf("%09lld\n", ans);
    else printf("%lld\n", ans);
    return 0;
}