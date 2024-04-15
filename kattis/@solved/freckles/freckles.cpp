#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int T, n;
double frecklex[1010];
double freckley[1010];
vector<tuple<double, int, int>> edge_list;
int mst_size;
double mst_cost;

class UnionFind {
private:
    vi id, rank;
    int num_sets;
public:
    UnionFind(int N) {
        id.assign(N, 0); for (int i = 0; i < N; i++) id[i] = i;
        rank.assign(N, 0);
        num_sets = N;
    }

    int find(int i) { return (id[i] == i) ? i : (id[i] = find(id[i])); }
    bool is_same_set(int i, int j) { return find(i) == find(j); }
    int size_sets() { return num_sets; }

    void join(int i, int j) {
        if (is_same_set(i, j)) return;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y]) swap(x, y);
        id[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        num_sets--;
    }
};

bool find_mst() {
    UnionFind uf(n);
    for (auto &[w, u, v]: edge_list) {
        if (uf.is_same_set(u, v)) continue;
        mst_cost += w;
        uf.join(u, v);
        mst_size++;
        if (mst_size == n - 1) return true;
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        edge_list.clear();
        mst_cost = 0;
        mst_size = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &frecklex[i], &freckley[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    edge_list.push_back({
                        hypot(frecklex[j] - frecklex[i], freckley[j] - freckley[i]),
                        i, j
                    });
                }
            }
        }
        sort(edge_list.begin(), edge_list.end());
        find_mst();
        printf("%.2lf\n", mst_cost);
    }
    return 0;
}