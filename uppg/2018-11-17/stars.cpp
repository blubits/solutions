#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, c = 1;
    while (scanf("%d %d", &m, &n) == 2) {
        char bmp[m][n];
        cin.ignore();
        for (int i = 0; i < m; i++) {
            string s;
            getline(cin, s);
            for (int j = 0; j < n; j++) {
                bmp[i][j] = s[j];
            }
        }
        int stars = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (bmp[i][j] == '-') {
                    stars++;
                    queue<pair<int, int>> ff;
                    bmp[i][j] = '#';
                    ff.push(make_pair(i, j));
                    while (!ff.empty()) {
                        auto p = ff.front();
                        auto x = p.first, y = p.second;
                        ff.pop();
                        // fill
                        // move

                        // U
                        if (x > 0 && bmp[x - 1][y] == '-') {
                            bmp[x - 1][y] = '#';
                            ff.push(make_pair(x - 1, y));
                        }
                        // D
                        if (x < m - 1 && bmp[x + 1][y] == '-') {
                            bmp[x + 1][y] = '#';
                            ff.push(make_pair(x + 1, y));
                        }
                        // L
                        if (y > 0 && bmp[x][y - 1] == '-') {
                            bmp[x][y - 1] = '#';
                            ff.push(make_pair(x, y - 1));
                        }
                        // R
                        if (y < n - 1 && bmp[x][y + 1] == '-') {
                            bmp[x][y + 1] = '#';
                            ff.push(make_pair(x, y + 1));
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", c++, stars);
    }
    return 0;
}
