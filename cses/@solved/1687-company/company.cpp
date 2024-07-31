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
vi parent;
int ancestor[20][200010];

void calculate_ancestors() {
    int MAX_K = ceil(log2(n)); 
    for (int v = 0; v <= n; v++) { ancestor[0][v] = parent[v]; }
    for (int k = 1; k <= MAX_K; k++) {
        for (int v = 0; v <= n; v++) {
            int mid = ancestor[k - 1][v];
            if (mid == -1) ancestor[k][v] = -1;
            else ancestor[k][v] = ancestor[k - 1][mid];
        }
    }
}

int get_ancestor(int v, int k) {
    int MAX_K = ceil(log2(n)); 
    for (int p = 0; p <= MAX_K; p++) {
        if (k & (1 << p)) {
            v = ancestor[p][v];
            if (v == -1) break;
        }
    }
    return v;
}

int main() {
    cin >> n >> q;
    parent.resize(n);
    parent[0] = -1; 
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
    }
    calculate_ancestors();
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        int ans = get_ancestor(a, b);
        cout << ans + (ans == -1 ? 0 : 1) << endl;
    }
    return 0;
}