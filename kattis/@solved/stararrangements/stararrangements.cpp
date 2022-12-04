#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    printf("%d:\n", k);
    for (int i = 2; i <= ceil(k / 2.0); i++) {
        // i, i - 1
        if (k % (i + i - 1) == 0 || k % (i + i - 1) == i)
            printf("%d,%d\n", i, i - 1);
        // i, i
        if (k % (i + i) == 0 || k % (i + i) == i) printf("%d,%d\n", i, i);
    }
    return 0;
}
