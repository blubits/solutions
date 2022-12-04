#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "unionfind.hpp"

#define CLUSTERS 4
int cluster(
    std::vector<std::pair<int, std::pair<int, int>>> &edges, int N) {
    std::sort(edges.begin(), edges.end());
    UnionFind uf(N);
    for (auto e: edges) {
        int u = e.second.first, v = e.second.second, wt = e.first;
        if (uf.find(u) != uf.find(v)) {
            if (uf.count_sets() > CLUSTERS) {
                uf.join(u, v);
            } else if (uf.count_sets() == CLUSTERS) {
                return wt;
            }
        }
    }
    return 0;
}

int main() {
    std::ifstream infile;
    infile.open("clustering1.txt");
    
    int N;
    infile >> N;
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    int a, b, w;
    while (infile >> a >> b >> w) {
        a--;
        b--;
        edges.push_back(std::make_pair(w, std::make_pair(a, b)));
    }
    std::cout << cluster(edges, N) << std::endl;
    return 0;
}