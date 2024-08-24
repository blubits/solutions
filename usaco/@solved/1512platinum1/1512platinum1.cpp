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

// Input
int n, k;
vector<vi> graph;

int ancestor[20][200010];  // Parent array
vector<int> depth;         // Depth array
vector<int> visited;       // Visited array

vector<int> starts_at;
vector<int> ends_at;

vector<int> num_paths;

void calculate_ancestors() {
    int MAX_K = ceil(log2(n));
    for (int k = 1; k <= MAX_K; k++) {
        for (int v = 0; v <= n; v++) {
            int mid = ancestor[k - 1][v];
            if (mid == -1)
                ancestor[k][v] = -1;
            else
                ancestor[k][v] = ancestor[k - 1][mid];
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
    return ancestor[0][u];  // or ancestor[0][v]
}

void generate_parent_depth_array(int v, int d, int p) {
    depth[v] = d;
    ancestor[0][v] = p;
    for (auto n : graph[v]) {
        if (depth[n] == -1) {
            generate_parent_depth_array(n, d + 1, v);
        }
    }
}

int process_answer(int v) {
    int num_paths_v = 0;
    visited[v] = true;
    for (auto n : graph[v]) {
        if (!visited[n]) {
            num_paths_v += process_answer(n);
        }
    }
    // relative to v:
    // left <-- v ---> right
    num_paths[v] = num_paths_v + starts_at[v] - ends_at[v] / 2;
    // relative to v:
    //         parent
    //           |
    // left <--- v ---> right
    return num_paths_v + starts_at[v] - ends_at[v];
}

int main() {
    freopen("maxflow.in", "r", stdin);
	freopen("maxflow.out", "w", stdout);
    cin >> n >> k;
    graph.resize(n);
    depth.resize(n, -1);

    starts_at.resize(n);
    ends_at.resize(n);
    visited.resize(n);
    num_paths.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    generate_parent_depth_array(0, 0, -1);
    calculate_ancestors();
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        starts_at[a]++;
        starts_at[b]++;
        ends_at[lca(a, b)] += 2;
    }
    process_answer(0);
    cout << *max_element(num_paths.begin(), num_paths.end()) << endl;
    return 0;
}