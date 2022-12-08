#include <iostream>
#include <string>

using namespace std;

int main() {
    int r, c, f = 1;
    while (cin >> r >> c && !(r == 0 && c == 0)) {
        if (f != 1) cout << endl;
        int board[r][c];
        cin.ignore();
        for (int i = 0; i < r; i++) {
            string row;
            getline(cin, row);
            for (int j = 0; j < c; j++) {
                if (row[j] == '*') {
                    board[i][j] = -1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] != -1) {
                    int b = 0;
                    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == -1)
                        b++;
                    if (i - 1 >= 0 && board[i - 1][j] == -1) b++;
                    if (i - 1 >= 0 && j + 1 < c && board[i - 1][j + 1] == -1)
                        b++;
                    if (j + 1 < c && board[i][j + 1] == -1) b++;
                    if (i + 1 < r && j + 1 < c && board[i + 1][j + 1] == -1)
                        b++;
                    if (i + 1 < r && board[i + 1][j] == -1) b++;
                    if (i + 1 < r && j - 1 >= 0 && board[i + 1][j - 1] == -1)
                        b++;
                    if (j - 1 >= 0 && board[i][j - 1] == -1) b++;
                    board[i][j] = b;
                }
            }
        }
        cout << "Field #" << f++ << ":" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == -1)
                    cout << "*";
                else
                    cout << board[i][j];
            }
            cout << endl;
        }
    }
}
