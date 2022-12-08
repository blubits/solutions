#include <cmath>
#include <iostream>

using namespace std;

int side, board[30][30];
bool rows[30][30], cols[30][30], sqrs[30][30];

int sqfy(int i, int j) {
    int ss = sqrt(side);
    return ((i / ss) * ss) + (j / ss);
}

int main() {
    int t;
    cin >> t;
start:
    while (t--) {
        cin >> side;
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                cin >> board[i][j];
                rows[i][j] = cols[i][j] = sqrs[i][j] = false;
            }
        }
        for (int i = 0; i < side; i++) {
            for (int j = 0; j < side; j++) {
                int bij = board[i][j] - 1;
                rows[i][bij] = true;
                cols[j][bij] = true;
                sqrs[sqfy(i, j)][bij] = true;
            }
        }
        for (int u = 0; u < side; u++) {
            for (int e = 0; e < side; e++) {
                if (!rows[u][e] || !cols[u][e] || !sqrs[u][e]) {
                    cout << "no" << endl;
                    goto start;
                }
            }
        }
        cout << "yes" << endl;
    }
}
