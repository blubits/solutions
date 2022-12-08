#include <cstdio>
#include <iostream>
using namespace std;

// WQU with path compression
class union_find {
   public:
    int size;
    int *id;
    int *sz;

   public:
    union_find(int x) {
        size = x;
        id = new int[x];
        sz = new int[x];
        for (int i = 0; i < size; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

   private:
    int root(int i) {
        int root = i, temp;
        while (root != id[root]) {
            root = id[root];
        }
        while (i != id[i]) {
            temp = id[i];
            id[i] = root;
            i = temp;
        }
        return root;
    }

   public:
    bool find(int p, int q) { return root(p) == root(q); }

    void join(int p, int q) {
        int pr = root(p);
        int qr = root(q);
        if (sz[pr] < sz[qr]) {
            id[pr] = qr;
            sz[qr] += sz[pr];
        } else {
            id[qr] = pr;
            sz[pr] += sz[qr];
        }
    }

    ~union_find() { delete[] id; }
};

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    union_find UF = union_find(n);
    while (q--) {
        char x;
        int a, b;
        scanf(" %c %d %d", &x, &a, &b);
        if (x == '?') {
            if (UF.find(a, b))
                printf("yes\n");
            else
                printf("no\n");
        } else {
            UF.join(a, b);
        }
    }
    return 0;
}
