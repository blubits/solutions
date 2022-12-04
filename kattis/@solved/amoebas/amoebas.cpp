#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int r, c, ans = 0;
    cin >> r >> c;
    string board[r];
    queue<pair<int, int>> q;
    cin.ignore();
    for (int i = 0; i < r; i++) getline(cin, board[i]);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '#') {
                ans++;
                q.push({i, j});
                while (!q.empty()) {
                    auto idx = q.front();
                    q.pop();
                    int ix = idx.first, iy = idx.second;
                    board[ix][iy] = '*';
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 && dy == 0) continue;
                            if (0 <= (ix + dx) && (ix + dx) < r &&
                                0 <= (iy + dy) && (iy + dy) < c &&
                                board[ix + dx][iy + dy] == '#') {
                                q.push({ix + dx, iy + dy});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
