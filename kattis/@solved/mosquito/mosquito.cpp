#include <cstdio>

using namespace std;

int main() {
    int m, p, l, e, r, s, n;
    while (scanf("%d %d %d %d %d %d %d\n", &m, &p, &l, &e, &r, &s, &n) == 7) {
        int cm = m, cp = p, cl = l;
        while (n--) {
            int nm, np, nl;
            nm = cp / s;
            np = cl / r;
            nl = cm * e;
            cm = nm;
            cp = np;
            cl = nl;
        }
        printf("%d\n", cm);
    }
}
