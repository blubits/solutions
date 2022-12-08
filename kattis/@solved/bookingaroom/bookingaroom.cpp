#include <cstdio>

using namespace std;

int main() {
    int r, n;
    scanf("%d %d", &r, &n);
    if (r == n)
        printf("too late\n");
    else {
        bool booked[r + 1];
        for (int i = 0; i <= r; i++) booked[i] = false;
        for (int i = 0; i < n; i++) {
            int ri;
            scanf("%d", &ri);
            booked[ri] = true;
        }
        for (int i = 1; i <= r; i++) {
            if (!booked[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
