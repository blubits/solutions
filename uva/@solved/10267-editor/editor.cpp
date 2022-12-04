#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    char c, board[260][260];
    int m = 260, n = 260;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = 'O';
        }
    }
    while (cin >> c && c != 'X') {
        if (c == 'I') {
            cin >> m >> n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    board[i][j] = 'O';
                }
            }
        } else if (c == 'C') {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    board[i][j] = 'O';
                }
            }
        } else if (c == 'L') {
            int x, y;
            char c;
            cin >> x >> y >> c;
            board[y - 1][x - 1] = c;
        } else if (c == 'V') {
            int x, y1, y2;
            char c;
            cin >> x >> y1 >> y2 >> c;
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                board[y - 1][x - 1] = c;
            }
        } else if (c == 'H') {
            int x1, x2, y;
            char c;
            cin >> x1 >> x2 >> y >> c;
            for (int x = min(x1, x2); x <= max(x1, x2); x++) {
                board[y - 1][x - 1] = c;
            }
        } else if (c == 'K') {
            int x1, y1, x2, y2;
            char c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                for (int x = min(x1, x2); x <= max(x1, x2); x++) {
                    board[y - 1][x - 1] = c;
                }
            }
        } else if (c == 'F') {
            int x, y;
            char c, f;
            cin >> x >> y >> c;
            bool in_queue[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    in_queue[i][j] = false;
                }
            }
            queue<pair<int, int>> visited;
            visited.push(make_pair(y - 1, x - 1));
            in_queue[y - 1][x - 1] = true;
            f = board[y - 1][x - 1];
            while (!visited.empty()) {
                auto p = visited.front();
                visited.pop();
                auto i = p.first, j = p.second;
                board[i][j] = c;
                if (i - 1 >= 0 && j - 1 >= 0 && !in_queue[i - 1][j - 1] &&
                    board[i - 1][j - 1] == f) {
                    in_queue[i - 1][j - 1] = true;
                    visited.push(make_pair(i - 1, j - 1));
                }
                if (i - 1 >= 0 && !in_queue[i - 1][j] && board[i - 1][j] == f) {
                    in_queue[i - 1][j] = true;
                    visited.push(make_pair(i - 1, j));
                }
                if (i - 1 >= 0 && j + 1 < m && !in_queue[i - 1][j + 1] &&
                    board[i - 1][j + 1] == f) {
                    in_queue[i - 1][j + 1] = true;
                    visited.push(make_pair(i - 1, j + 1));
                }
                if (j + 1 < m && !in_queue[i][j + 1] && board[i][j + 1] == f) {
                    in_queue[i][j + 1] = true;
                    visited.push(make_pair(i, j + 1));
                }
                if (i + 1 < n && j + 1 < m && !in_queue[i + 1][j + 1] &&
                    board[i + 1][j + 1] == f) {
                    in_queue[i + 1][j + 1] = true;
                    visited.push(make_pair(i + 1, j + 1));
                }
                if (i + 1 < n && !in_queue[i + 1][j] && board[i + 1][j] == f) {
                    in_queue[i + 1][j] = true;
                    visited.push(make_pair(i + 1, j));
                }
                if (i + 1 < n && j - 1 >= 0 && !in_queue[i + 1][j - 1] &&
                    board[i + 1][j - 1] == f) {
                    in_queue[i + 1][j - 1] = true;
                    visited.push(make_pair(i + 1, j - 1));
                }
                if (j - 1 >= 0 && !in_queue[i][j - 1] && board[i][j - 1] == f) {
                    in_queue[i][j - 1] = true;
                    visited.push(make_pair(i, j - 1));
                }
            }
        } else if (c == 'S') {
            string filename;
            cin >> filename;
            cout << filename << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << board[i][j];
                }
                cout << endl;
            }
        } else {
            cin.ignore();
        }
    }
}
