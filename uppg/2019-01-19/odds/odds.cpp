#include <cstdio>

using namespace std;

int value(int d1, int d2) {
    int d;
    if (d1 > d2)
        d = (d1 * 10) + d2;
    else
        d = (d2 * 10) + d1;
    if (d == 21)
        return 10000;
    else if (d % 11 == 0)
        return d * 100;
    else
        return d;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    bool win[7][7][7][7] = {false};
    int won[7][7][7][7] = {0}, games[7][7][7][7] = {0};
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                for (int l = 1; l <= 6; l++) {
                    if (value(i, j) > value(k, l)) {
                        win[i][j][k][l] = true;
                        won[0][0][0][0]++;
                        won[0][0][0][l]++;
                        won[0][0][k][0]++;
                        won[0][0][k][l]++;
                        won[0][j][0][0]++;
                        won[0][j][0][l]++;
                        won[0][j][k][0]++;
                        won[0][j][k][l]++;
                        won[i][0][0][0]++;
                        won[i][0][0][l]++;
                        won[i][0][k][0]++;
                        won[i][0][k][l]++;
                        won[i][j][0][0]++;
                        won[i][j][0][l]++;
                        won[i][j][k][0]++;
                        won[i][j][k][l]++;
                    }
                    games[0][0][0][0]++;
                    games[0][0][0][l]++;
                    games[0][0][k][0]++;
                    games[0][0][k][l]++;
                    games[0][j][0][0]++;
                    games[0][j][0][l]++;
                    games[0][j][k][0]++;
                    games[0][j][k][l]++;
                    games[i][0][0][0]++;
                    games[i][0][0][l]++;
                    games[i][0][k][0]++;
                    games[i][0][k][l]++;
                    games[i][j][0][0]++;
                    games[i][j][0][l]++;
                    games[i][j][k][0]++;
                    games[i][j][k][l]++;
                }
            }
        }
    }
    char cs0, cs1, cr0, cr1;
    int s0, s1, r0, r1;
    while (scanf("%c %c %c %c\n", &cs0, &cs1, &cr0, &cr1) &&
           !(cs0 == '0' && cs1 == '0' && cr0 == '0' && cr1 == '0')) {
        if (cs0 == '*')
            s0 = 0;
        else
            s0 = cs0 - '0';
        if (cs1 == '*')
            s1 = 0;
        else
            s1 = cs1 - '0';
        if (cr0 == '*')
            r0 = 0;
        else
            r0 = cr0 - '0';
        if (cr1 == '*')
            r1 = 0;
        else
            r1 = cr1 - '0';
        // printf("%d %d %d %d\n", s0, s1, r0, r1);
        if (won[s0][s1][r0][r1] == 0)
            printf("0\n");
        else if (won[s0][s1][r0][r1] == games[s0][s1][r0][r1])
            printf("1\n");
        else {
            int a = won[s0][s1][r0][r1], b = games[s0][s1][r0][r1];
            int k = gcd(a, b);
            printf("%d/%d\n", a / k, b / k);
        }
    }
    return 0;
}
