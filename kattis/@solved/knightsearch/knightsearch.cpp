#include <iostream>
#include <string>

using namespace std;

int N;
string board;
string text = "ICPCASIASG";

int knight_r[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int knight_c[] = {1, -1, 2, -2, 2, -2, 1, -1};

int indexify(int i, int j) { return N * i + j; }

bool search(int len, int starting_cell) {
    // cout << len << " " << starting_cell << endl;
    if (len == 10) return true;
    if (starting_cell == -1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[indexify(i, j)] == text[len]) {
                    if (search(len + 1, indexify(i, j))) return true;
                }
            }
        }
    } else {
        int r = starting_cell / N, c = starting_cell % N;
        for (int i = 0; i < 8; i++) {
            if (indexify(r + knight_r[i], c + knight_c[i]) >= 0 &&
                board[indexify(r + knight_r[i], c + knight_c[i])] ==
                    text[len]) {
                if (search(len + 1, indexify(r + knight_r[i], c + knight_c[i])))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> board;
    if (search(0, -1))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
    return 0;
}
