#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

#define INF 100000000;

double tsp_helper(int S, int j, std::vector<std::vector<double>>& ltour,
                  std::vector<std::vector<double>>& dist, int N) {
    if (S == ((1 << N) - 1)) {
        return dist[j][0];
    }
    if (ltour[j][S] != -1) return ltour[j][S];
    double ans = INF;
    for (int k = 0; k < N; k++) {
        if (S & (1 << k)) continue;  // already visited
        ans = std::min(
            ans, dist[k][j] + tsp_helper(S | (1 << k), k, ltour, dist, N));
    }
    ltour[j][S] = ans;
    return ans;
}

double tsp(std::vector<std::vector<double>>& dist, int N) {
    std::vector<std::vector<double>> ltour(N);
    for (int i = 0; i < N; i++) {
        ltour[i].assign(1 << N, -1);
    }
    return tsp_helper(0, 0, ltour, dist, N);
}

int main() {
    std::fstream infile;
    infile.open("tsp.txt");

    int N;
    infile >> N;
    double x[N], y[N];
    for (int i = 0; i < N; i++) {
        infile >> x[i] >> y[i];
    }
    std::vector<std::vector<double>> dist(N);
    for (int i = 0; i < N; i++) {
        dist[i].assign(N, 0);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = hypot(x[j] - x[i], y[j] - y[i]);
        }
    }
    std::cout << tsp(dist, N) << std::endl;
}