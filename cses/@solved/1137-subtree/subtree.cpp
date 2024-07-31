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

    SegTreeNode(int L, int R)
        : L(L), R(R), value(0), left(nullptr), right(nullptr) {}
};

class PURQSegTree {
   private:
    SegTreeNode *root;
    vector<int> A;

    ll combine(ll left, ll right) { return left + right; }

    SegTreeNode *build(int L, int R) {
        SegTreeNode *node = new SegTreeNode(L, R);
        if (L == R) {
            node->value = A[L];
            return node;
        }
        int m = (L + R) / 2;
        node->left = build(L, m);
        node->right = build(m + 1, R);
        node->value = combine(node->left->value, node->right->value);
        return node;
    }

    ll query_rec(SegTreeNode* node, int i, int j) {
        if (node == nullptr || i > j) return 0; 
        if (i == node->L && j == node->R) return node->value;
        int m = (node->L + node->R) / 2;
        return combine(
            query_rec(node->left, i, min(m, j)),
            query_rec(node->right, max(m + 1, i), j)
        );
    }

    void update_rec(SegTreeNode* node, int i, int v) {
        if (!(node->L <= i && i <= node->R)) return;
        if (i == node->L && i == node->R) {
            A[i] = v;
            node->value = v;
            return;
        }
        update_rec(node->left, i, v);
        update_rec(node->right, i, v);
        node->value = combine(node->left->value, node->right->value);
    }

   public:
    PURQSegTree(vector<int> arr) {
        A = arr;
        root = build(0, A.size() - 1);
    }

    ll query(int i, int j) {
        return query_rec(root, i, j);
    }

    void update(int i, int v) {
        update_rec(root, i, v);
    }
};

vector<vi> graph;
vector<int> value, tt, idx, sz;
vector<bool> visited;
int timer = 0;

void dfs_euler_tour(int v) {
	visited[v] = true;
	idx[v] = timer++;
	tt[idx[v]] = value[v];
	for (int n: graph[v]) {
		if (!visited[n]) dfs_euler_tour(n);
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
    dfs_euler_tour(0);
    PURQSegTree* st = new PURQSegTree(tt);
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            st->update(idx[s], x);
        } else {
            int s;
            cin >> s;
            s--;
            auto [a, b] = subtree_at(s);
            cout << st->query(a, b) << endl;
        }
    }
    return 0; 
}