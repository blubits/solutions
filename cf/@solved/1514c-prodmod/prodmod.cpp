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
    int N;
    ll product = 1;
    cin >> N;
    vector<int> coprimes;
    for (int i = 1; i < N; i++) {
        if (gcd(i, N) == 1) {
            coprimes.push_back(i);
            product *= i;
            product %= N;
        }
    }
    if (product != 1) {
        coprimes.pop_back();
    }
    cout << coprimes.size() << endl;
    for (auto cp: coprimes) cout << cp << " ";
    cout << endl;
    return 0;
}