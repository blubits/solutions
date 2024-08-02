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

int n, q;
vector<int> succ;

int succ_bin[32][200010];

void calculate_successors() {
    int MAX_K = 29; 
    for (int v = 0; v <= n; v++) { succ_bin[0][v] = succ[v]; }
    for (int k = 1; k <= MAX_K; k++) {
        for (int v = 0; v <= n; v++) {
            succ_bin[k][v] = succ_bin[k - 1][succ_bin[k - 1][v]];
        }
    }
}

int get_successor(int v, int k) {
    int MAX_K = 29; 
    for (int p = 0; p <= MAX_K; p++) {
        if (k & (1 << p)) {
            v = succ_bin[p][v];
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> q;
    succ.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> succ[i];
        succ[i]--;
    }
    calculate_successors();
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        cout << get_successor(a, b) + 1 << endl;
    }
    return 0;
}