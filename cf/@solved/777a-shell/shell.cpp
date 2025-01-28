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
    int n, x;
    cin >> n >> x;
    n %= 6;
    for (int i = n; i >= 1; i--) {
        if (i % 2 == 0) {
            // even move
            if (x == 2) x = 1;
            else if (x == 1) x = 2;
        } else {
            // odd move
            if (x == 0) x = 1;
            else if (x == 1) x = 0;
        }
    }
    cout << x << endl;
    return 0;
}