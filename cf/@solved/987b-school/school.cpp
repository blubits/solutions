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

// key: "magnitude" of ln(x)/x
int key(int x) {
    switch (x) {
        case 3:
            return INF;
        case 2:
        case 4:
            return INF - 10;
        case 1:
            return NINF*2;
        default:
            return -x;
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    if (key(x) < key(y)) {
        cout << '<';
    } else if (key(x) > key(y)) {
        cout << '>';
    } else {
        cout << '=';
    }
    cout << endl;
    return 0;
}