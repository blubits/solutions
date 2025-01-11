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

// Returns the sum of all integers between a and b.
int sum(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
}

int main() {
    int w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    if (d1 < d2) {
        swap(d1, d2);
        swap(u1, u2);
    }
    // step 1: h -> d1
    w += sum(d1, h);
    w = max(0, w - u1);
    // step 2: d1 -> d2
    w += sum(d2, d1 - 1);
    w = max(0, w - u2);
    // step 3: d2 -> bottom
    w += sum(0, d2 - 1);
    cout << w << endl;
    return 0;
}