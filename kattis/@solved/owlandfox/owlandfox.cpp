#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k, mult = 1;
        scanf("%d", &k);
        while (k % 10 == 0) {
            k /= 10;
            mult *= 10;
        }
        printf("%d\n", (k - 1) * mult);
    }
    return 0;
}
