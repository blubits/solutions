#include <algorithm>
#include <iostream>
#include <vector>

class DisjointSet {
    int n;
    int max_rows;
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> sz;

   public:
    DisjointSet(int n, std::vector<int> sizes) : n(n), max_rows(-1) {
        parent.reserve(n);
        rank.reserve(n);
        sz.reserve(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            sz[i] = sizes[i];
            max_rows = std::max(max_rows, sz[i]);
        }
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int get_max() { return max_rows; }

    void join(int a, int b) {
        int roota = find(a), rootb = find(b);

        if (roota == rootb) return;
        // make it so that rootb will always have the lower rank
        if (rank[roota] < rank[rootb]) {
            int temp = roota;
            roota = rootb;
            rootb = temp;
        }
        parent[rootb] = roota;
        if (rank[roota] == rank[rootb]) {
            rank[roota]++;
        }
        sz[roota] += sz[rootb];
        max_rows = std::max(max_rows, sz[roota]);
    }
};

int main() {
    int N, q;
    std::cin >> N >> q;
    std::vector<int> sizes(N);
    for (int i = 0; i < N; i++) std::cin >> sizes[i];
    DisjointSet tables(N, sizes);
    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        tables.join(a - 1, b - 1);
        std::cout << tables.get_max() << std::endl;
    }
}
