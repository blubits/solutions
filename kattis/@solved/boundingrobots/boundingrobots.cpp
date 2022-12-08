#include <cstdio>

using namespace std;

int main() {
    int w, l;
    while (scanf("%d %d\n", &w, &l) && !(w == 0 && l == 0)) {
        int x = 0, y = 0, xr = 0, yr = 0;
        int t;
        scanf("%d\n", &t);
        while (t--) {
            char ins;
            int step;
            scanf("%c %d\n", &ins, &step);
            if (ins == 'u') {
                yr += step;
                y += step;
                if (y >= l) y = l - 1;
            } else if (ins == 'd') {
                yr -= step;
                y -= step;
                if (y < 0) y = 0;
            } else if (ins == 'l') {
                xr -= step;
                x -= step;
                if (x < 0) x = 0;
            } else if (ins == 'r') {
                xr += step;
                x += step;
                if (x >= w) x = w - 1;
            }
        }
        printf("Robot thinks %d %d\n", xr, yr);
        printf("Actually at %d %d\n\n", x, y);
    }
}
