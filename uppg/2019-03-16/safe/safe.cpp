#include <algorithm>
#include <iostream>

#define INF 1000000000

using namespace std;

int safe[3][3];

void press(int button, int tot_times) {
    if (tot_times == 0) return;
    int r = button / 3, c = button % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == r || c == j) {
                safe[i][j] = (safe[i][j] + 4 + tot_times) % 4;
            }
        }
    }
}

int min_moves(int curr_button, int tot_times) {
    if (curr_button == 9) {
        bool solved = true;
        for (int i = 0; i < 3 && solved; i++) {
            for (int j = 0; j < 3 && solved; j++) {
                if (safe[i][j] != 0) solved = false;
            }
        }
        if (solved)
            return tot_times;
        else
            return INF;
    }
    int min_all = INF;
    for (int curr_times = 0; curr_times < 4; curr_times++) {
        press(curr_button, curr_times);
        int min_curr = min_moves(curr_button + 1, tot_times + curr_times);
        min_all = min(min_all, min_curr);
        press(curr_button, -curr_times);
    }

    return min_all;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> safe[i][j];
        }
    }
    int m = min_moves(0, 0);
    if (m == INF)
        cout << -1;
    else
        cout << m;
    cout << endl;
}
