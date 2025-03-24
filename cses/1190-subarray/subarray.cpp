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

struct STNodeData {
    ll max_subarray_sum;
    ll sum;
    ll max_prefix_sum;
    ll max_suffix_sum;

    STNodeData(ll max_subarray_sum, ll sum, ll max_prefix_sum,
               ll max_suffix_sum)
        : max_subarray_sum(max_subarray_sum),
          sum(sum),
          max_prefix_sum(max_prefix_sum),
          max_suffix_sum(max_suffix_sum) {}

    STNodeData()
        : max_subarray_sum(0), sum(0), max_prefix_sum(0), max_suffix_sum(0) {}
};

STNodeData combine(const STNodeData &left, const STNodeData &right) {
    return STNodeData(
        max(max(left.max_subarray_sum, right.max_subarray_sum),
            left.max_suffix_sum + right.max_prefix_sum),
        left.sum + right.sum,
        max(left.max_prefix_sum, left.sum + right.max_prefix_sum),
        max(right.max_suffix_sum, left.max_suffix_sum + right.sum));
}

class STNode {
   public:
    int L, R;
    STNodeData data;
    STNode *left, *right;

    STNode(int L, int R) : L(L), R(R) {}
};

class SegmentTree {
    STNode *root;
    vector<ll> A;

    STNode *rec_build(int L, int R) {
        STNode *node = new STNode(L, R);
        if (L == R) {
            node->data = STNodeData(max(0LL, A[L]), A[L], max(0LL, A[L]),
                                    max(0LL, A[L]));
            return node;
        }
        int M = (L + R) / 2;
        node->left = rec_build(L, M);
        node->right = rec_build(M + 1, R);
        node->data = combine(node->left->data, node->right->data);
        return node;
    }

    STNodeData rec_query(STNode *node, int L, int R) {
        if (L == node->L && R == node->R) {
            return node->data;
        }
        int M = (node->L + node->R) / 2;
        if (R <= M) {
            return rec_query(node->left, L, R);
        } else if (L > M) {
            return rec_query(node->right, L, R);
        } else {
            return combine(rec_query(node->left, L, M),
                           rec_query(node->right, M + 1, R));
        }
    }

    void rec_update(STNode *node, int i, ll v) {
        if (node->L == node->R) {
            node->data = STNodeData(max(0LL, v), v, max(0LL, v), max(0LL, v));
            A[i] = v;
            return;
        }
        int M = (node->L + node->R) / 2;
        if (i <= M) {
            rec_update(node->left, i, v);
        } else {
            rec_update(node->right, i, v);
        }
        node->data = combine(node->left->data, node->right->data);
    }

   public:
    SegmentTree(vector<ll> &A) : A(A) { root = rec_build(0, A.size() - 1); }
    ll query(int L, int R) { return rec_query(root, L, R).max_subarray_sum; }
    void update(int i, ll v) { rec_update(root, i, v); }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Fill A[i] until power of 2.
    while (n & (n - 1)) {
        A.push_back(0);
        n++;
    }
    SegmentTree st(A);
    while (m--) {
        int k; ll x;
        cin >> k >> x;
        st.update(k - 1, x);
        cout << st.query(0, n - 1) << endl;
    }
}