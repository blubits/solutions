#include <vector>

#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
    private:
    int sz;
    int sets;
    std::vector<int> id;
    std::vector<int> rank;

    public:
    UnionFind(int sz);
    int find(int i);
    void join(int i, int j);
    int count_sets();
};

#endif