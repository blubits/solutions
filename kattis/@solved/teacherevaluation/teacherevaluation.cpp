#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int main() {
    int n, t, sum = 0;
    cin >> n >> t;
    if (t == 100) cout << "impossible";
    else {
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            sum += k;
        }
        cout << int(ceil((sum - n * t) / (double(t - 100)))) << endl;
    }
    return 0;
}