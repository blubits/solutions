#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int dist[n + 1];
    for (int i = 1; i <= n; i++) scanf("%d", &dist[i]);
    while (q--) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int c, d;
            scanf("%d %d", &c, &d);
            dist[c] = d;
        } else if (qt == 2) {
            int c1, c2;
            scanf("%d %d", &c1, &c2);
            printf("%d\n", abs(dist[c1] - dist[c2]));
        }
    }
    return 0;
}
