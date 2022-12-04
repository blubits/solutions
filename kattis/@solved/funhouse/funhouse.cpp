#include <cstdio>

using namespace std;

void reflect_rl(int &di, int &dj) {
    //    v
    // -> / <-
    //    ^
    if (di == 1 && dj == 0) {
        // DOWN -> LEFT
        di = 0;
        dj = -1;
    } else if (di == -1 && dj == 0) {
        // UP -> RIGHT
        di = 0;
        dj = 1;
    } else if (di == 0 && dj == 1) {
        // RIGHT -> UP
        di = -1;
        dj = 0;
    } else if (di == 0 && dj == -1) {
        // LEFT -> DOWN
        di = 1;
        dj = 0;
    }
}

void reflect_ll(int &di, int &dj) {
    //    v
    // -> \ <-
    //    ^
    if (di == 1 && dj == 0) {
        // DOWN -> RIGHT
        di = 0;
        dj = 1;
    } else if (di == -1 && dj == 0) {
        // UP -> LEFT
        di = 0;
        dj = -1;
    } else if (di == 0 && dj == 1) {
        // RIGHT -> DOWN
        di = 1;
        dj = 0;
    } else if (di == 0 && dj == -1) {
        // LEFT -> UP
        di = -1;
        dj = 0;
    }
}

void determine_initial_movement(int io, int jo, int r, int c, int &di,
                                int &dj) {
    if (io == 0) {
        di = 1;
        dj = 0;
    } else if (io == r - 1) {
        di = -1;
        dj = 0;
    } else if (jo == 0) {
        di = 0;
        dj = 1;
    } else if (jo == c - 1) {
        di = 0;
        dj = -1;
    }
}

int main() {
    int h = 1, c, r;
    while (scanf("%d %d ", &c, &r) && !(c == 0 && r == 0)) {
        int io, jo;
        char funhouse[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%c ", &funhouse[i][j]);
                if (funhouse[i][j] == '*') {
                    io = i;
                    jo = j;
                }
            }
        }
        int di, dj;
        determine_initial_movement(io, jo, r, c, di, dj);
        while (funhouse[io][jo] != '&') {
            // printf("%d %d %d %d %c\n", io, jo, di, dj, funhouse[io][jo]);
            io += di;
            jo += dj;
            if (funhouse[io][jo] == '\\')
                reflect_ll(di, dj);
            else if (funhouse[io][jo] == '/')
                reflect_rl(di, dj);
            else if (funhouse[io][jo] == 'x') {
                funhouse[io][jo] = '&';
            }
        }
        // printf("%d %d %d %d %c\n", io, jo, di, dj, funhouse[io][jo]);
        printf("HOUSE %d\n", h++);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%c", funhouse[i][j]);
            }
            printf("\n");
        }
    }
}
