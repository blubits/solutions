#include <cstdio>

using namespace std;

int main() {
    int sp, q, t = 0;
    bool c = false;
    scanf("%d\n%d", &sp, &q);
    sp -= 1;
    while (q--) {
        int ti;
        char zi;
        scanf("%d %c", &ti, &zi);
        if (c) continue;
        t += ti;
        if (t >= 210) {
            printf("%d\n", sp + 1);
            c = true;
        }
        if (zi == 'T') sp = (sp + 1) % 8;
    }
    return 0;
}
