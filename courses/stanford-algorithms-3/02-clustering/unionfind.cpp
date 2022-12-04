#include "unionfind.hpp"

UnionFind::UnionFind(int sz) : sz(sz), sets(sz) {
    id.resize(sz);
    rank.resize(sz);
    for (int i = 0; i < sz; i++) {
        id[i] = i;
        rank[i] = 0;
    }
}

int UnionFind::find(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void UnionFind::join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return;
    sets--;
    if (rank[i] < rank[j]) {
        int a = i;
        i = j;
        j = a;
    }
    id[j] = i;
    if (rank[i] == rank[j]) {
        rank[i]++;
    }
}

int UnionFind::count_sets() {
    return sets;
}