#include <cstdio>

using namespace std;

int main() {
    int h, c;
    while (1) {
        scanf("%d", &h);
        if (h == 0) return 0;
        scanf("%d", &c);
        int k, kp;
        scanf("%d", &k);
        c--;
        kp = k;
        int l = h - k;
        while (c--) {
            scanf("%d", &k);
            if (k < kp) l += (kp - k);
            kp = k;
        }
        printf("%d\n", l);
    }
}
