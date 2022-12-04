#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#include "unionfind.hpp"

unsigned int distance(unsigned int x, unsigned int y) {
    return __builtin_popcount(x ^ y);
}

int bs_index(std::vector<unsigned int> &v, unsigned int data,
             std::unordered_map<unsigned int, int> &idx_map) {
    auto it = idx_map.find(data);
    if (it != idx_map.end()) {
        return it->second;
    } else {
        return -1;
    }
}

int count_clusters(std::vector<unsigned int> &numbers,
                   std::unordered_map<unsigned int, int> &idx_map) {
    int clusters = 0;
    for (int i = 0; i < numbers.size(); i++) {
        unsigned int curr = numbers[i];
        if (idx_map[curr] == -1) continue;
        clusters++;
        std::queue<int> cluster;
        cluster.push(curr);
        while (!cluster.empty()) {
            int node = cluster.front();
            cluster.pop();
            idx_map[node] = -1;

            // All numbers n s.t. distance(node, n) = 1:
            for (int i = 0; i < 24; i++) {
                int next = node ^ (1 << i);
                int idx = bs_index(numbers, next, idx_map);
                if (idx != -1 && idx_map.at(next) != -1) {
                    idx_map[next] = -1;
                    cluster.push(next);
                }
            }
            // All numbers n s.t. distance(node, n) = 2:
            for (int i = 0; i < 24; i++) {
                for (int j = i + 1; j < 24; j++) {
                    int next = node ^ ((1 << i) | (1 << j));
                    int idx = bs_index(numbers, next, idx_map);
                    if (idx != -1 && idx_map.at(next) != -1) {
                        idx_map[next] = -1;
                        cluster.push(next);
                    }
                }
            }
        }
        if (i % 1000 == 0) std::cout << clusters << std::endl;
    }
    return clusters;
}

int main() {
    std::ifstream infile;
    infile.open("clustering_big.txt");

    int N, B;
    infile >> N >> B;
    std::vector<unsigned int> numbers(N);
    std::unordered_map<unsigned int, int> idx;
    for (int i = 0; i < N; i++) {
        unsigned int k = 0;
        for (int j = 0; j < B; j++) {
            unsigned int kb;
            infile >> kb;
            k = (k | kb) << 1;
        }
        numbers[i] = k >> 1;
        idx[k >> 1] = i;
    }
    std::cout << count_clusters(numbers, idx) << std::endl;
    return 0;
}