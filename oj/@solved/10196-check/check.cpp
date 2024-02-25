#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#define NO_CHECK 0
#define BLACK_CHECK 100
#define WHITE_CHECK 200

using namespace std;

bool in_bounds(int i, int j) { return (0 <= i && i < 8) && (0 <= j && j < 8); }

int seek(char board[8][8], int i, int j) {
    char piece = board[i][j];
    int IN_CHECK;
    if (!(piece == 'K' || piece == 'k')) return NO_CHECK;
    if (piece == 'K')
        IN_CHECK = WHITE_CHECK;
    else
        IN_CHECK = BLACK_CHECK;

    // opposing pieces
    char p = 'p', n = 'n', b = 'b', r = 'r', q = 'q', k = 'k';
    if (piece == 'k') {
        // white pieces attack black king
        p = 'P';
        n = 'N';
        b = 'B';
        r = 'R';
        q = 'Q';
        k = 'K';
    }

    vector<pair<int, int>> pawn_white = {{1, -1}, {1, 1}};
    vector<pair<int, int>> pawn_black = {{-1, -1}, {-1, 1}};
    vector<pair<int, int>> bishop = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    vector<pair<int, int>> rook = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<pair<int, int>> knight = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1},
                                     {1, -2},  {2, -1},  {2, 1},  {1, 2}};

    // seek pawn
    if (p == 'P') {
        for (auto m : pawn_white) {
            int ix = i + m.first, jx = j + m.second;
            if (in_bounds(ix, jx) && board[ix][jx] == p) return IN_CHECK;
        }
    } else {
        for (auto m : pawn_black) {
            int ix = i + m.first, jx = j + m.second;
            // cout << piece << " " << board[ix][jx] << endl;
            if (in_bounds(ix, jx) && board[ix][jx] == p) return IN_CHECK;
        }
    }

    // seek knight;
    // check knight movements
    for (auto m : knight) {
        int ix = i + m.first, jx = j + m.second;
        if (in_bounds(ix, jx) && board[ix][jx] == n) return IN_CHECK;
    }

    // seek king;
    // check surroundings
    for (auto m : rook) {
        int ix = i + m.first, jx = j + m.second;
        if (in_bounds(ix, jx) && board[ix][jx] == k) return IN_CHECK;
    }
    for (auto m : bishop) {
        int ix = i + m.first, jx = j + m.second;
        if (in_bounds(ix, jx) && board[ix][jx] == k) return IN_CHECK;
    }

    // seek rook OR queen;
    // linear search
    for (auto m : rook) {
        int ix = i + m.first, jx = j + m.second;
        while (in_bounds(ix, jx)) {
            if (board[ix][jx] == r) return IN_CHECK;
            if (board[ix][jx] == q) return IN_CHECK;
            if (board[ix][jx] != '.') break;
            ix += m.first;
            jx += m.second;
        }
    }

    // seek bishop OR queen;
    // diagonal search
    for (auto m : bishop) {
        int ix = i + m.first, jx = j + m.second;
        while (in_bounds(ix, jx)) {
            if (board[ix][jx] == b) return IN_CHECK;
            if (board[ix][jx] == q) return IN_CHECK;
            if (board[ix][jx] != '.') break;
            ix += m.first;
            jx += m.second;
        }
    }

    return NO_CHECK;
}

int main() {
    string l;
    int c = 1;
    char board[8][8];
    while (getline(cin, l)) {
        bool all_blank = true;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = l[j];
                if (l[j] != '.') all_blank = false;
            }
            if (i == 7) break;
            getline(cin, l);
        }
        if (all_blank) break;
        int result = NO_CHECK;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'k' || board[i][j] == 'K') {
                    result = max(result, seek(board, i, j));
                }
            }
        }
        cout << "Game #" << c++ << ": ";
        if (result == NO_CHECK)
            cout << "no";
        else if (result == BLACK_CHECK)
            cout << "black";
        else if (result == WHITE_CHECK)
            cout << "white";
        cout << " king is in check." << endl;
        cin.ignore();
    }
}
