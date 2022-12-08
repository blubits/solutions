#include <cstdio>

using namespace std;

int main() {
    int s, b;
    while (scanf("%d %d", &s, &b) && s != 0 && b != 0) {
        int next[s + 2];
        int prev[s + 2];
        next[0] = 1;
        prev[0] = -1;
        next[s + 1] = -1;
        prev[s + 1] = s;
        for (int i = 1; i <= s; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        int l, r;
        while (b--) {
            scanf("%d %d", &l, &r);
            next[prev[l]] = next[r];
            prev[next[r]] = prev[l];
            int la = prev[next[r]], ra = next[prev[l]];
            if (la == 0 && ra == s + 1) {
                printf("* *");
            } else if (la == 0) {
                printf("* %d", ra);
            } else if (ra == s + 1) {
                printf("%d *", la);
            } else {
                printf("%d %d", la, ra);
            }
            printf("\n");
        }
        printf("-\n");
    }
    return 0;
}
