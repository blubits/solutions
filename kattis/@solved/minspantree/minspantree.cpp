#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

class UnionFind {
private:
    vi id, rank, size;
    int num_sets;
public:
    UnionFind(int N) {
        id.assign(N, 0); for (int i = 0; i < N; i++) id[i] = i;
        rank.assign(N, 0);
        size.assign(N, 1);
        num_sets = N;
    }

    int find(int i) { return (id[i] == i) ? i : (id[i] = find(id[i])); }
    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int size_sets() { return num_sets; }
    int size_of_set(int i) { return size[find(i)]; }

    void join(int i, int j) {
        if (is_same_set(i, j)) return;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y]) swap(x, y);
        id[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        size[y] += size[x];
        num_sets--;
    }
};

int n, m;
vector<pair<int, ii>> edge_list;

vector<ii> mst;
int mst_cost;

// kruskal's
bool find_mst() {
    UnionFind uf(n);
    for (auto &[w, e]: edge_list) {
        auto &[u, v] = e;
        if (uf.is_same_set(u, v)) continue;
        mst_cost += w;
        uf.join(u, v);
        mst.push_back({min(u, v), max(u, v)});
        if (mst.size() == n - 1) return true;
    }
    return false;
}

int main() {
    while (cin >> n >> m && !(n + m == 0)) {
        edge_list.clear();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edge_list.push_back({w, {u, v}});
        }
        mst_cost = 0;
        mst.clear();
        sort(edge_list.begin(), edge_list.end());
        if (find_mst()) {
            cout << mst_cost << endl;
            sort(mst.begin(), mst.end());
            for (auto &[u, v]: mst) cout << u << " " << v << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}