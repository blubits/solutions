#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    cin.ignore();
    vector<string> board, words;
    for (int i = 0; i < r; i++) {
        string line;
        getline(cin, line);
        board.push_back(line);
    }
    // check rowwise
    for (int i = 0; i < r; i++) {
        string w;
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '#') {
                if (w.size() > 1) words.push_back(w);
                w.clear();
            } else {
                w += board[i][j];
            }
        }
        if (w.size() > 1) words.push_back(w);
    }
    // check columnwise
    for (int j = 0; j < c; j++) {
        string w;
        for (int i = 0; i < r; i++) {
            if (board[i][j] == '#') {
                if (w.size() > 1) words.push_back(w);
                w.clear();
            } else {
                w += board[i][j];
            }
        }
        if (w.size() > 1) words.push_back(w);
    }
    sort(words.begin(), words.end());
    cout << words[0] << endl;
    return 0;
}
