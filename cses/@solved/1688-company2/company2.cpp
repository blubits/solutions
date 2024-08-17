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
vi depth;
vector<vi> graph;
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

void calculate_depth(int u, int d) {
    depth[u] = d;
    for (auto n: graph[u]) {
        if (depth[n] == -1) {
            calculate_depth(n, d + 1);
        }
    }
}

int lca(int u, int v) {
	
	// WLOG, make u be the deeper node
	if (depth[u] < depth[v]) return lca(v, u);

	// move u up to v
	u = get_ancestor(u, depth[u] - depth[v]);

	// if u == v now, then v is u's ancestor
	if (u == v) return v;

    int MAX_K = ceil(log2(n)); 
	for (int k = MAX_K; k >= 0; k--) {
		if (ancestor[k][u] != ancestor[k][v]) {
			u = ancestor[k][u];
			v = ancestor[k][v];
		}
	}
	
	// at the end, u and v will still not be equal
	// because of the if statement
	// but their parents should be equal:
	return ancestor[0][u]; // or ancestor[0][v]
}

int main() {
    cin >> n >> q;
    parent.resize(n);
    depth.resize(n, -1);
    graph.resize(n);
    parent[0] = -1; 
    for (int i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
        graph[parent[i]].push_back(i);
        graph[i].push_back(parent[i]);
    }
    calculate_ancestors();
    calculate_depth(0, 0);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << lca(a, b) + 1 << endl;
    }
    return 0;
}