#include <cstdio>

using namespace std;

int main() {
    int factorial[11] = {1, 1, 2, 6, 4, 0, 0, 0, 0, 0, 0};
    int t;
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", factorial[k]);
    }
    return 0;
}
