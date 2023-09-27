#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int AM[100][100];
int pairs = -1;
set<int> vertices;

float average() {
    for (int k = 0; k < 100; k++) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
            }
        }
    }
    float sum = 0;
    for (auto u: vertices) {
        for (auto v: vertices) {
            if (u == v) continue;
            sum += AM[u][v];
        }
    }
    return sum / pairs;
}

int main() {
    int i, j, T = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            AM[i][j] = INF;
        }
    }
    while (1) {
        cin >> i >> j;
        if (i == 0 && j == 0) {
            pairs = vertices.size() * vertices.size() - vertices.size();
            if (pairs == 0) break;
            printf("Case %d: average length between pages = %.3f clicks\n", T++, average());
            vertices.clear();
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    AM[i][j] = INF;
                }
            }
            continue;
        }
        AM[i - 1][j - 1] = 1;
        vertices.insert(i - 1);
        vertices.insert(j - 1);
    }
}