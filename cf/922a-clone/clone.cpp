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
    int x, y;
    cin >> x >> y;
    int calc = x - (y - 1);
    if (y == 1 && x == 0) cout << "Yes" << endl;
    else if (y > 1 && (calc >= 0 && calc % 2 == 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}