#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int r, c;
    cin >> r >> c;
    char board[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'W') {
                // check for adjacent S
                if (i > 0 && board[i - 1][j] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
                if (i < r - 1 && board[i + 1][j] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
                if (j > 0 && board[i][j - 1] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
                if (j < c - 1 && board[i][j + 1] == 'S') {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '.') {
                cout << "D";
            } else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}