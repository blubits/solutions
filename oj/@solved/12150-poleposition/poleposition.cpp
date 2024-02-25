#include <cstdio>

using namespace std;

int main() {
    int t;
    while (scanf("%d", &t) && t != 0) {
        int posn[t], c, dp;
        bool invalid = false;
        for (int i = 0; i < t; i++) posn[i] = -1;
        for (int i = 0; i < t; i++) {
            scanf("%d %d", &c, &dp);
            if (invalid) continue;
            if (i + dp >= t || i + dp < 0 || posn[i + dp] != -1) {
                invalid = true;
                printf("-1");
            } else {
                posn[i + dp] = c;
            }
        }
        if (!invalid) {
            for (int i = 0; i < t; i++) {
                if (i != 0) printf(" ");
                printf("%d", posn[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
