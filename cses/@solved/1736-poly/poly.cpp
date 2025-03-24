/**
 * A pointer-based, non-generic implementation of a segment tree
 * that supports range sum queries and range series updates.
 * Uses lazy propagation.
 */

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll IDENTITY = 0;
ll combine(ll a, ll b) { return a + b; }

// A node in the segment tree.
struct LazySegTreeNode {
    int L, R;
    ll answer;
    ll lazy_start, lazy_diff;
    LazySegTreeNode *left, *right;
    LazySegTreeNode(int l, int r)
        : L(l),
          R(r),
          answer(0),
          lazy_start(0),
          lazy_diff(0),
          left(nullptr),
          right(nullptr) {}
};

// A segment tree.
// Supports range sum queries and range increment updates.
struct LazySegTree {
    LazySegTreeNode *root;
    int sz;
    vector<ll> A;

   private:
    LazySegTreeNode *build(int l, int r);
    ll range_query(LazySegTreeNode *node, int qi, int qj);
    void range_series_update(LazySegTreeNode *node, int qi, int qj, ll start);
    void lazy_update(LazySegTreeNode *node, ll start, ll diff);
    void propagate(LazySegTreeNode *node);

   public:
    LazySegTree(int n) : sz(n), A(n) { root = build(0, n - 1); }
    LazySegTree(vector<ll> &L) : sz(L.size()), A(L) { root = build(0, sz - 1); }
    ll range_query(int qi, int qj) { return range_query(root, qi, qj); }
    void range_series_update(int qi, int qj) {
        range_series_update(root, qi, qj, ll(1));
    }
};

/**
 * Builds a node of a segment tree that represents the slice A[l:r].
 */
LazySegTreeNode *LazySegTree::build(int l, int r) {
    LazySegTreeNode *node = new LazySegTreeNode(l, r);
    if (l == r) {
        node->answer = A[l];
        return node;
    }
    int m = (l + r) / 2;
    node->left = build(l, m);
    node->right = build(m + 1, r);
    node->answer = combine(node->left->answer, node->right->answer);
    return node;
}

ll sum(ll a1, ll n, ll d) { return (n * (2 * a1 + (n - 1) * d)) / 2; }

/**
 * Updates a node of a segment tree and marks it as lazily updated.
 */
void LazySegTree::lazy_update(LazySegTreeNode *node, ll start, ll diff) {
    if (node == nullptr) return;
    int len = node->R - node->L + 1;
    // Undo previously-committed lazy update
    node->answer -= sum(node->lazy_start, len, node->lazy_diff);
    // Commit update
    node->lazy_start += start;
    node->lazy_diff += diff;
    // Add currently-committed lazy update
    node->answer += sum(node->lazy_start, len, node->lazy_diff);
}

/**
 * If a lazy update exists on a node, commits the change to its children
 * and clears the lazy update.
 */
void LazySegTree::propagate(LazySegTreeNode *node) {
    if (node->lazy_start) {
        lazy_update(node->left, node->lazy_start, node->lazy_diff);
        // When propagating a change right, make sure that you are
        // propagating the correct start/diff points.
        // If my current diff is 2, for example, we have to take that
        // into account when we calculate start_end.
        // e.g. {3, 5, 7, 9}
        // start_right = 7 = start * (diff + len(left))
        int start_right = node->lazy_start +
                          node->lazy_diff * (node->left->R - node->left->L + 1);
        lazy_update(node->right, start_right, node->lazy_diff);
        node->lazy_start = 0;
        node->lazy_diff = 0;
    }
}

/**
 * Queries a node of a segment tree for the sum of the slice A[qi:qj].
 */
ll LazySegTree::range_query(LazySegTreeNode *node, int qi, int qj) {
    // Invalid query; returns the identity element.
    if (qi > qj) return IDENTITY;
    // Current node fully encompasses A[qi:qj].
    if (node->L == qi && node->R == qj) {
        return node->answer;
    }
    // Otherwise, the answer can be found within the node's left and right
    // children. We make sure that the left and right children are updated
    // first, which is done by calling `propagate`.
    propagate(node);
    return combine(range_query(node->left, qi, min(qj, node->left->R)),
                   range_query(node->right, max(qi, node->right->L), qj));
}

void LazySegTree::range_series_update(LazySegTreeNode *node, int qi, int qj,
                                      ll start) {
    // Invalid query; returns the identity element.
    if (qi > qj) return;
    // Current node fully encompasses A[qi:qj].
    if (node->L == qi && node->R == qj) {
        // When we update a node, we maintain the following invariant:
        // A node is "lazily updated" if the range sum it contains
        // is correct, but none of its descendants have the correct value.
        // In other words, the node is "lazily updated" if the node
        // has not propagated the update down.
        //
        // Whenever we visit a node, we *always* have to make sure that
        // the range sum update it contains is correct.
        // This is why we call `propagate` on a node right before we visit
        // its children. When we recurse to each child, we already know
        // that the children have correct range query info.
        lazy_update(node, start, 1);
        return;
    }
    // As before, if none of the cases above hold, we need to update
    // both the left and right child.
    // Since we are recursing on the left and right children, we want
    // to make sure to update the left and right children first through
    // `propagate`, to make sure that the children have correct information
    // when we recurse to them.
    propagate(node);
    ll start_right = max(ll(1), start + (node->right->L - qi));
    range_series_update(node->left, qi, min(qj, node->left->R), start);
    range_series_update(node->right, max(qi, node->right->L), qj, start_right);
    node->answer = combine(node->left->answer, node->right->answer);
}

int main() {
    /**
     * Input format:
     *
     * The first line contains two integers $N$ and $Q$.
     * The second line contains $N$ integers $A_1, \ldots, A_N$, the list
     * that we are operating on.
     * Each of the next $Q$ lines contains queries of two types:
     * - A query of type $1$ contains two integers $i$ and $j$. This query
     *   returns the sum of $A_i + A_{i + 1} + \ldots + A_j$.
     * - A query of type $2$ contains three integers $i$, $j$, and $k$.
     *   This query increments all of the values $A_i$, $A_{i + 1}$,
     *   $\ldots$, $A_j$ by $k$.
     */

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // Pad the end of the array with the identity element,
    // until the array has length $2^k$ for some $k$.
    // This will make debugging the segment tree easier.
    while (N & (N - 1)) {
        A.push_back(IDENTITY);
        N++;
    }

    LazySegTree tree(A);
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 2) {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            cout << tree.range_query(i, j) << endl;
        } else {
            int i, j;
            cin >> i >> j;
            i--;
            j--;
            tree.range_series_update(i, j);
        }
    }
    return 0;
}