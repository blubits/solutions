#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int w, h, n;
    while (scanf("%d %d %d", &w, &h, &n) && (w != 0 || h != 0 || n != 0)) {
        bool board[501][501] = {false};
        while (n--) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for (int i = min(y1, y2); i <= max(y1, y2); i++) {
                for (int j = min(x1, x2); j <= max(x1, x2); j++) {
                    board[i][j] = true;
                }
            }
        }
        int empty = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (!board[i][j]) {
                    empty++;
                }
            }
        }
        if (empty == 0)
            printf("There is no empty spots.");
        else if (empty == 1)
            printf("There is one empty spot.");
        else
            printf("There are %d empty spots.", empty);
        printf("\n");
    }
    return 0;
}
