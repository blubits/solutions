#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t, l, w;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &l, &w);
        printf("%d\n", (int)(ceil((l - 2) / 3.0) * ceil((w - 2) / 3.0)));
    }
    return 0;
}
