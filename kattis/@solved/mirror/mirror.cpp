#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t, a = 1;
    cin >> t;
    vector<string> board;
    while (t--) {
        int r, c;
        cin >> r >> c;
        cin.ignore();
        for (int i = 0; i < r; i++) {
            string line;
            getline(cin, line);
            board.push_back(line);
        }
        cout << "Test " << a++ << endl;
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                cout << board[i][j];
            }
            cout << endl;
        }
        board.clear();
    }
    return 0;
}
