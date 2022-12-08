#include <iostream>

using namespace std;

const int B = 100;
const int R = 200;
const int Y = 300;
const int W = 400;

int stotk(string token) {
    if (token == "BB")
        return B;
    else if (token == "RR")
        return R;
    else if (token == "YY")
        return Y;
    else if (token == "WW")
        return W;
    return 0;
}

int main() {
    string token;
    while (cin >> token && token != "**") {
        int tk = stotk(token);
        int board[5][5];
        string line;
        for (int i = 0; i <= 4; i++) {
            cin >> line;
            for (int j = 0; j < i + 1; j++) {
                board[i][j] = stotk(line.substr(2 * j, 2));
            }
        }
        bool jumpable = false;
        cout << "tk: " << tk << endl;
        for (int i = 0; i <= 4; i++) {
            for (int j = 0; j < i + 1; j++) {
                cout << board[i][j] << "\t";
                if (board[i][j] != tk) continue;
                // jump up
                if (i - 2 >= 0 && board[i - 2][j] == 0 && board[i - 1][j] != 0)
                    jumpable = true;
                // jump down
                if (i + 2 <= 4 && board[i + 2][j] == 0 && board[i + 1][j] != 0)
                    jumpable = true;
                // jump left
                if (j - 2 >= 0 && board[i][j - 2] == 0 && board[i][j - 1] != 0)
                    jumpable = true;
                // jump right
                if (j + 2 < i + 1 && board[i][j + 2] == 0 &&
                    board[i][j + 1] != 0)
                    jumpable = true;
            }
            cout << endl;
        }
        if (jumpable)
            cout << "Possible";
        else
            cout << "Impossible";
        cout << endl;
    }
}
