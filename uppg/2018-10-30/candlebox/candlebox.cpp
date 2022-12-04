#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int d, r, t;
    scanf("%d\n%d\n%d", &d, &r, &t);
    int total = r + t;
    int ra = 4, rc = 0;
    int ta = ra - d, tc = 0;
    while (true) {
        rc += ra;
        if (ta >= 3) tc += ta;
        if (rc + tc == total) {
            printf("%d\n", abs(rc - r));
            break;
        }
        ta++;
        ra++;
    }
    return 0;
}
