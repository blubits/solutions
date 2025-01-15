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
    char start, finish;
    int n;
    cin >> start >> finish >> n;
    int start_idx, finish_idx;
    switch (start) {
        case 'v': start_idx = 0; break;
        case '<': start_idx = 1; break;
        case '^': start_idx = 2; break;
        case '>': start_idx = 3; break;
    }
    switch (finish) {
        case 'v': finish_idx = 0; break;
        case '<': finish_idx = 1; break;
        case '^': finish_idx = 2; break;
        case '>': finish_idx = 3; break;
    }
    if ((start_idx + n) % 4 == (start_idx - (n % 4) + 4) % 4) {
        cout << "undefined" << endl;
    } else if ((start_idx + n) % 4 == finish_idx) {
        cout << "cw" << endl;
    } else if ((start_idx - (n % 4) + 4) % 4 == finish_idx) {
        cout << "ccw" << endl;
    } else {
        cout << "undefined" << endl;
    }
    return 0;
}