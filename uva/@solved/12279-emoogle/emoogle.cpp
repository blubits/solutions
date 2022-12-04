#include <cstdio>

using namespace std;

int main() {
    int x, xi, c = 1;
    while (1) {
        scanf("%d", &x);
        if (x == 0) break;
        int in = 0, out = 0;
        while (x--) {
            scanf("%d", &xi);
            if (xi == 0)
                out++;
            else
                in++;
        }
        printf("Case %d: %d\n", c, in - out);
        c++;
    }
    return 0;
}
