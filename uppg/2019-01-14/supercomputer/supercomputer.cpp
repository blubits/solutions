#include <iostream>
#include <vector>

using namespace std;

class segtree {
   public:
    int n;
    vector<int> tree;

   public:
    segtree(int size) {
        n = size;
        tree.resize(3000000, 0);
    }

    void flip(int i) {
        // update root
        i = n + i;
        if (tree[i] == 0) {
            tree[i] = 1;
        } else {
            tree[i] = 0;
        }
        // update ancestors of root
        for (int j = i; j > 1; j >>= 1) {
            // ancestor  =   left  +  right
            tree[j >> 1] = tree[j] + tree[j ^ 1];
        }
    }

    void debug() {
        for (int i = 0; i < 2 * n; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    segtree ST = segtree(n);
    string token;
    while (q--) {
        cin >> token;
        if (token == "F") {
            int bit;
            cin >> bit;
            ST.flip(bit - 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ST.query(l - 1, r) << endl;
        }
    }
    return 0;
}
