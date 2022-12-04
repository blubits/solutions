#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define INF 100000000;

double tsp_nn(std::vector<std::vector<double>> &dist, int N) {
    std::bitset<33708> visited;
    double ans = 0;
    int last_vertex = 0;
    while (!visited.all()) {
        int nn = 0;
        double nn_length = INF;
        for (int i = 0; i < N; i++) {
            if (!visited.test(i)) {
                if (dist[last_vertex][i] < nn_length) {
                    nn_length = dist[last_vertex][i];
                    nn = i;
                }
            }
        }
        visited.set(nn);
        // std::cout << last_vertex << " -> " << nn << std::endl;
        ans += nn_length;
        last_vertex = nn;
    }
    return ans + dist[last_vertex][0];
}

int main() {
    std::fstream infile;
    infile.open("nn.txt");

    int N;
    infile >> N;
    double x[N], y[N];
    int i;
    while (infile >> i) {
        infile >> x[i - 1] >> y[i - 1];
    }
    std::vector<std::vector<double>> dist(N);
    for (int i = 0; i < N; i++) {
        dist[i].assign(N, 0);
        for (int j = 0; j < N; j++) {
            dist[i][j] = hypot(x[j] - x[i], y[j] - y[i]);
        }
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << tsp_nn(dist, N) << std::endl;
}