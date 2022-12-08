#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int r, c, ans = 0;
    cin >> r >> c;
    int board[r][c], dist[r][c];
    queue<pair<int, int>> q;
    cin.ignore();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            board[i][j] = int(c - '0');
            dist[i][j] = 1000000000;
        }
    };
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto idx = q.front();
        q.pop();
        int ix = idx.first, iy = idx.second;
        int a = board[ix][iy];
        if (a == 0) {
            continue;
        }
        int dirx[4] = {0, 0, a, -a}, diry[4] = {a, -a, 0, 0};
        for (int i = 0; i < 4; i++) {
            int dx = dirx[i], dy = diry[i];
            if (0 <= (ix + dx) && (ix + dx) < r && 0 <= (iy + dy) &&
                (iy + dy) < c) {
                if (dist[ix + dx][iy + dy] > dist[ix][iy] + 1) {
                    dist[ix + dx][iy + dy] = dist[ix][iy] + 1;
                    q.push({ix + dx, iy + dy});
                }
            }
        }
    }
    if (dist[r - 1][c - 1] != 1000000000)
        cout << dist[r - 1][c - 1];
    else
        cout << -1;
    cout << endl;
    return 0;
}
