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
    int r, c;
    cin >> r >> c;
    int x, y, rad = 1;
    bool is_b = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                if (!is_b) {x = i; y = j; is_b = true;}
                else {rad++;}
            } else {
                if (is_b) {
                    cout << 1 + x + (rad / 2) << " " << 1 + y + (rad / 2) << endl;
                    return 0;
                }
            }
        }
        if (is_b) break;
    }
    cout << 1 + x + (rad / 2) << " " << 1 + y + (rad / 2) << endl;
    return 0;
}