#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char process(char c) {
    if ('A' <= c && c <= 'Z') {
        return tolower(c);
    }
    if ('a' <= c && c <= 'z') {
        return toupper(c);
    }
    return c;
}

int main() {
    int c = 0;
    string line;
    vector<string> board;
    vector<pair<char, pair<int, int>>> dots;
    while (!cin.eof()) {
        if (c++) cout << endl;
        board.clear();
        dots.clear();
        while (getline(cin, line) && line != "") {
            board.push_back(line);
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.')
                    dots.push_back({process(board[i][j]), {i, j}});
            }
        }
        sort(dots.begin(), dots.end());
        auto cdot = dots[0];
        for (int i = 1; i < dots.size(); i++) {
            if (cdot.second.first == dots[i].second.first) {
                int a = cdot.second.first;
                int st = min(cdot.second.second, dots[i].second.second);
                int en = max(cdot.second.second, dots[i].second.second);
                // same row, diff column
                for (int b = st + 1; b < en; b++) {
                    if (board[a][b] == '.')
                        board[a][b] = '-';
                    else if (board[a][b] == '|')
                        board[a][b] = '+';
                }
            } else if (cdot.second.second == dots[i].second.second) {
                int b = cdot.second.second;
                int st = min(cdot.second.first, dots[i].second.first);
                int en = max(cdot.second.first, dots[i].second.first);
                // same row, diff column
                for (int a = st + 1; a < en; a++) {
                    if (board[a][b] == '.')
                        board[a][b] = '|';
                    else if (board[a][b] == '-')
                        board[a][b] = '+';
                }
            }
            cdot = dots[i];
        }
        for (auto &l : board) cout << l << endl;
    }
}
