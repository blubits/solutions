#include <iostream>

using namespace std;

// int num_games;
// int num_won;

double orchard[5][5][5][5][9];

double simulate(int r, int g, int b, int y, int s) {
    if (!(r + g + b + y) && s) return 1;
    if (!s) return 0;
    if (orchard[r][g][b][y][s] != 0) return orchard[r][g][b][y][s];

    double prob = 0;
    int branches = 6;
    if (r != 0)
        prob += simulate(r - 1, g, b, y, s);
    else
        branches--;
    if (g != 0)
        prob += simulate(r, g - 1, b, y, s);
    else
        branches--;
    if (b != 0)
        prob += simulate(r, g, b - 1, y, s);
    else
        branches--;
    if (y != 0)
        prob += simulate(r, g, b, y - 1, s);
    else
        branches--;

    int m = max(max(r, g), max(b, y));
    if (r == m)
        prob += simulate(r - 1, g, b, y, s);
    else if (g == m)
        prob += simulate(r, g - 1, b, y, s);
    else if (b == m)
        prob += simulate(r, g, b - 1, y, s);
    else if (y == m)
        prob += simulate(r, g, b, y - 1, s);

    prob += simulate(r, g, b, y, s - 1);
    prob /= branches;

    orchard[r][g][b][y][s] = prob;
    return prob;
}

int main() {
    int r, g, b, y, s;
    scanf("%d %d %d %d %d", &r, &g, &b, &y, &s);
    printf("%.12lf\n", simulate(r, g, b, y, s));
}
