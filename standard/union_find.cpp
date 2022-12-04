#include <iostream>

using namespace std;

class union_find {
    int size;
    int *id;
    int *sz;

    int root(int i);

   public:
    union_find(int x);
    ~union_find();
    bool find(int p, int q);
    void join(int p, int q);
    int set_size(int p);
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
    union_find UF = union_find(10);

    return 0;
}
