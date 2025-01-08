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
    vi p(3);
    int d;
    cin >> p[0] >> p[1] >> p[2] >> d;
    sort(p.begin(), p.end());
    cout << max(0, d - (p[1] - p[0])) + max(0, d - (p[2] - p[1])) << endl;
    return 0;
}