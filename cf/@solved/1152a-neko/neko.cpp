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
    int n, m;
    cin >> n >> m;
    int even_chest = 0, odd_chest = 0, even_key = 0, odd_key = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k % 2 == 0) even_chest++;
        else odd_chest++;
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if (k % 2 == 0) even_key++;
        else odd_key++;
    }
    cout << min(even_chest, odd_key) + min(odd_chest, even_key) << endl;
    return 0;
}