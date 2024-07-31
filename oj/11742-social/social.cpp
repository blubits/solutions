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
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        vector<int> seats(n);
        vector<iii> constraints;
        for (int i = 0; i < n; i++) seats[i] = i;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            constraints.push_back({a, b, c});
        }
        int ans = 0;
        do {
            
        } while (next_permutation(seats.begin(), seats.end()))
    }
    return 0;
}