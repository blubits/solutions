#include <cstdio>

using namespace std;

int main() {
    int t;
    while (scanf("%d", &t) && t != -1) {
        int h, hp = 0, speed, d = 0;
        while (t--) {
            scanf("%d %d", &speed, &h);
            d += speed * (h - hp);
            hp = h;
        }
        printf("%d miles\n", d);
    }
    return 0;
}
