#include <cstdio>
using namespace std;

int main() {
    int k, q, r, b, n, p;
    scanf("%d %d %d %d %d %d", &k, &q, &r, &b, &n, &p);
    k = 1 - k;
    q = 1 - q;
    r = 2 - r;
    b = 2 - b;
    n = 2 - n;
    p = 8 - p;
    printf("%d %d %d %d %d %d\n", k, q, r, b, n, p);
    return 0;
}
