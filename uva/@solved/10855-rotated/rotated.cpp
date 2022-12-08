#include <iostream>
#include <string>

using namespace std;

int main() {
    int x, y;
    while (cin >> x >> y && x != 0 && y != 0) {
        string board[x], board90[x], board180[x], board270[x], pattern[y];
        int o = 0, o90 = 0, o180 = 0, o270 = 0;
        cin.ignore();
        for (int i = 0; i < x; i++) {
            getline(cin, board[i]);
        }
        for (int i = 0; i < y; i++) {
            getline(cin, pattern[i]);
        }
        // rotate 90
        for (int i = x - 1; i >= 0; i--) {
            string s = "";
            for (int j = 0; j < x; j++) {
                s += board[j][i];
            }
            board90[x - i - 1] = s;
        }
        // rotate 180
        for (int i = x - 1; i >= 0; i--) {
            string s;
            for (int j = 0; j < x; j++) {
                s += board90[j][i];
            }
            board180[x - i - 1] = s;
        }
        // rotate 270
        for (int i = x - 1; i >= 0; i--) {
            string s;
            for (int j = 0; j < x; j++) {
                s += board180[j][i];
            }
            board270[x - i - 1] = s;
        }
        // search
        for (int i = 0; i <= x - y; i++) {
            for (int j = 0; j <= x - y; j++) {
                // 0
                bool f0 = true;
                for (int a = 0; a < y; a++) {
                    for (int b = 0; b < y; b++) {
                        if (board[i + a][j + b] != pattern[a][b]) {
                            f0 = false;
                            break;
                        }
                    }
                }
                if (f0) o++;
                // 90
                bool f90 = true;
                for (int a = 0; a < y; a++) {
                    for (int b = 0; b < y; b++) {
                        if (board90[i + a][j + b] != pattern[a][b]) {
                            f90 = false;
                            break;
                        }
                    }
                }
                if (f90) o90++;
                // 180
                bool f180 = true;
                for (int a = 0; a < y; a++) {
                    for (int b = 0; b < y; b++) {
                        if (board180[i + a][j + b] != pattern[a][b]) {
                            f180 = false;
                            break;
                        }
                    }
                }
                if (f180) o180++;
                // 270
                bool f270 = true;
                for (int a = 0; a < y; a++) {
                    for (int b = 0; b < y; b++) {
                        if (board270[i + a][j + b] != pattern[a][b]) {
                            f270 = false;
                            break;
                        }
                    }
                }
                if (f270) o270++;
            }
        }
        cout << o << " " << o90 << " " << o180 << " " << o270 << endl;
    }
    return 0;
}
