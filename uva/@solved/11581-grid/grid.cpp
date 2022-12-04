#include <iostream>

using namespace std;

int board[3][3], new_board[3][3];

bool not_zeroed() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j]) return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char k;
        cin.ignore();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> k;
                board[i][j] = k - '0';
                new_board[i][j] = 0;
            }
        }
        int ans = -1;
        while (!not_zeroed()) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    new_board[i][j] = (i > 0 ? board[i - 1][j] : 0) +
                                      (j > 0 ? board[i][j - 1] : 0) +
                                      (i < 2 ? board[i + 1][j] : 0) +
                                      (j < 2 ? board[i][j + 1] : 0);
                    new_board[i][j] %= 2;
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = new_board[i][j];
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
}
