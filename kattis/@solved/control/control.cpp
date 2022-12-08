#include <iostream>
#include <set>
#include <vector>

using namespace std;

class union_find {
    int size;
    int *id;
    int *sz;

   public:
    union_find(int x);
    ~union_find();
    bool find(int p, int q);
    void join(int p, int q);
    int set_size(int p);
    int root(int i);
};

union_find::union_find(int x) {
    size = x;
    id = new int[x];
    sz = new int[x];
    for (int i = 0; i < size; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

union_find::~union_find() {
    delete[] id;
    delete[] sz;
}

int union_find::root(int i) {
    int root = i;
    while (root != id[root]) {
        root = id[root];
    }
    int temp;
    while (i != id[i]) {
        temp = id[i];  // save current node's parent
        id[i] = root;  // current node's parent is now the root
        i = temp;      // go up
    }
    return root;
}

bool union_find::find(int p, int q) { return root(p) == root(q); }

void union_find::join(int p, int q) {
    int pr = root(p);
    int qr = root(q);
    if (pr == qr) return;
    if (sz[pr] < sz[qr]) {
        id[pr] = qr;
        sz[qr] += sz[pr];
        sz[pr] = sz[qr];
    } else {
        id[qr] = pr;
        sz[pr] += sz[qr];
        sz[qr] = sz[pr];
    }
}

int union_find::set_size(int p) { return sz[root(p)]; }

int main() {
    union_find uf(500001);
    int k, ans = 0;
    cin >> k;
    while (k--) {
        int t;
        vector<int> ing;
        set<int> ingset;
        cin >> t;
        for (int i = 0; i < t; i++) {
            int k;
            cin >> k;
            ing.push_back(k);
            ingset.insert(uf.root(k));
        }
        int num_sets = 0;
        for (auto p : ingset) {
            num_sets += uf.set_size(p);
        }
        // cout << num_sets << " ";
        // for (auto p : ingset) cout << p << " ";
        if (num_sets == t) {
            // cout << "*";
            ans++;
            for (int i = 1; i < t; i++) {
                uf.join(ing[0], ing[i]);
            }
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}
