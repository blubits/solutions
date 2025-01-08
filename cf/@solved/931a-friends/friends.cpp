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
    int a, b;
    cin >> a >> b;
    int m = (a + b) / 2;
    int da = abs(a - m), db = abs(b - m);
    cout << ((da * (da + 1)) + (db * (db + 1))) / 2 << endl;
    return 0;
}