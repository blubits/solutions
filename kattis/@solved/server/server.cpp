#include <cstdio>

using namespace std;

int main() {
    int n, t, rt = 0;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        rt += k;
        if (rt > t) {
            printf("%d\n", i);
            break;
        }
        if (i == n - 1) {
            printf("%d\n", n);
            break;
        }
    }
    return 0;
}
