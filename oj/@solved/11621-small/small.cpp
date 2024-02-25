#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<ll> factors;
vector<ll> twos, threes;

int main() {
    ll t = 2, tr = 3;
    for (ll i = 1; i <= 31; i++) {
        twos.push_back(t);
        factors.push_back(t);
        t *= 2;
    }
    for (ll i = 1; i <= 19; i++) {
        threes.push_back(tr);
        factors.push_back(tr);
        tr *= 3;
    }
    factors.push_back(1);
    for (ll two: twos) {
        for (ll three: threes) {
            factors.push_back(two * three);
        }
    }
    sort(factors.begin(), factors.end());
    int N;
    while (cin >> N && N != 0) {
        cout << *lower_bound(factors.begin(), factors.end(), N) << endl;
    }
    return 0;
}