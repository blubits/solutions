#include <cstdio>

#define MAXINT 1 << 30

using namespace std;

int main() {
    int s, v1, v2;
    scanf("%d %d %d\n", &s, &v1, &v2);
    int ab1 = -1, ab2 = -1;
    for (int b2 = 0; b2 <= (s / v2); b2++) {
        int t1 = s - (b2 * v2);
        if (t1 % v1 == 0) {
            ab1 = t1 / v1;
            ab2 = b2;
            break;
        }
    }
    if (ab1 + ab2 == -2)
        printf("Impossible\n");
    else
        printf("%d %d\n", ab1, ab2);
}
