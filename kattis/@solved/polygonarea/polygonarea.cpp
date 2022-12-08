#include <cstdio>

using namespace std;

int main() {
    int t;
    while (scanf("%d", &t) && t != 0) {
        int x[t], y[t];
        for (int i = 0; i < t; i++) {
            scanf("%d %d", &x[i], &y[i]);
        }
        // Shoelace formula:
        // https://en.wikipedia.org/wiki/Shoelace_formula
        int l = 0, r = 0;
        for (int i = 0; i < t; i++) {
            l += x[i] * y[(i + 1) % t];
            r += x[(i + 1) % t] * y[i];
        }
        if (l - r > 0) {
            printf("CCW %.1lf\n", 0.5 * (l - r));
        } else {
            printf("CW %.1lf\n", 0.5 * (r - l));
        }
    }
    return 0;
}
