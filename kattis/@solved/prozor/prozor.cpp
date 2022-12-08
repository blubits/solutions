#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int r, c, s;
    cin >> r >> c >> s;
    cin.ignore();
    vector<string> window;
    for (int i = 0; i < r; i++) {
        string line;
        getline(cin, line);
        window.push_back(line);
    }
    int mi = 0, mj = 0, mf = 0;
    for (int i = 0; i <= r - s; i++) {
        for (int j = 0; j <= c - s; j++) {
            int f = 0;
            for (int a = 1; a <= s - 2; a++) {
                for (int b = 1; b <= s - 2; b++) {
                    if (window[i + a][j + b] == '*') f++;
                }
            }
            if (f > mf) {
                mf = f;
                mi = i;
                mj = j;
            }
        }
    }
    cout << mf << endl;
    for (int i = mi; i < mi + s; i++) {
        for (int j = mj; j < mj + s; j++) {
            if (i == mi && j == mj)
                window[i][j] = '+';
            else if (i == mi + s - 1 && j == mj)
                window[i][j] = '+';
            else if (i == mi && j == mj + s - 1)
                window[i][j] = '+';
            else if (i == mi + s - 1 && j == mj + s - 1)
                window[i][j] = '+';
            else if (i == mi || i == mi + s - 1)
                window[i][j] = '-';
            else if (j == mj || j == mj + s - 1)
                window[i][j] = '|';
        }
    }
    for (auto row : window) cout << row << endl;
    return 0;
}
