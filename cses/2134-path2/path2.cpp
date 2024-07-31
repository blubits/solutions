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
 
struct SegTreeNode {
    SegTreeNode *left, *right;
    int L, R;
    ll value;
    bool lazy;
    ll lazy_value;
 
    SegTreeNode(int L, int R)
        : L(L), R(R), value(0), left(nullptr), right(nullptr), lazy(false), lazy_value(0) {}
};
 
class RUPQSegTree {
   private:
    SegTreeNode *root;
    vector<ll> A;

    SegTreeNode *build(int L, int R) {
        SegTreeNode *node = new SegTreeNode(L, R);
        if (L == R) {
            node->value = A[L];
            return node;
        }
        int m = (L + R) / 2;
        node->left = build(L, m);
        node->right = build(m + 1, R);
        node->value = 0;
        return node;
    }
 
    void propagate(SegTreeNode* node) {
        if (node->lazy) {
            if (node->L == node->R) {
                node->value += node->lazy_value;
                A[node->L] += node->lazy_value;
            } else {
                // NOTE: += to avoid overwriting double lazy commits.
                node->left->lazy_value += node->lazy_value;
                node->right->lazy_value += node->lazy_value;
                node->left->lazy = true;
                node->right->lazy = true;
            }
            node->lazy_value = 0;
            node->lazy = false;
        }
    }
 
    ll query_rec(SegTreeNode* node, int i) {
        propagate(node);
        if (node == nullptr) return 0; 
        if (i == node->L && i == node->R) return node->value;
        int m = (node->L + node->R) / 2;
        if (node->L <= i && i <= m) return query_rec(node->left, i);
        else return query_rec(node->right, i);
    }
 
    void update_rec(SegTreeNode* node, int i, int j, ll dv) {
        if ((i > j) || !(node->L <= i && j <= node->R)) return;
        propagate(node);
        if (i == node->L && j == node->R) {
            node->lazy = true;
            node->lazy_value = dv;
            return;
        }
        int m = (node->L + node->R) / 2;
        update_rec(node->left, i, min(m, j), dv);
        update_rec(node->right, max(m+1, i), j, dv);
    }
 
   public:
    RUPQSegTree(vector<ll> arr) {
        A = arr;
        root = build(0, A.size() - 1);
    }
 
    ll query(int i) {
        return query_rec(root, i);
    }
 
    void update(int i, int j, ll dv) {
        update_rec(root, i, j, dv);
    }
};
 
vector<vi> graph;
vector<ll> tt, value;
vector<int> idx, sz;
vector<bool> visited;
int timer = 0;
 
void dfs_euler_tour(int v, ll sum) {
	visited[v] = true;
	idx[v] = timer++;
	tt[idx[v]] = value[v] + sum;
	for (int n: graph[v]) {
		if (!visited[n]) dfs_euler_tour(n, value[v] + sum);
	}
	sz[v] = timer - idx[v];
}
 
pair<int, int> subtree_at(int v) {
	return {idx[v], idx[v] + sz[v] - 1};
}
 
int main() { 
    int n, q;
    cin >> n >> q;
    graph.resize(n);
    value.resize(n);
    tt.resize(n); idx.resize(n); sz.resize(n); visited.resize(n);
    for (int i = 0; i < n; i++) cin >> value[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs_euler_tour(0, 0);
    RUPQSegTree* st = new RUPQSegTree(tt);
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int s; ll x;
            cin >> s >> x;
            s--;
            ll dv = x - value[s];
            value[s] = x;
            auto [a, b] = subtree_at(s);
            st->update(a, b, dv);
        } else {
            int s;
            cin >> s;
            s--;
            cout << st->query(idx[s]) << endl;
        }
    }
    return 0; 
}