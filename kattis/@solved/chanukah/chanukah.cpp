#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int c, n;
        scanf("%d %d", &c, &n);
        printf("%d %d\n", c, ((n * (n + 1)) / 2) + n);
    }
    return 0;
}
