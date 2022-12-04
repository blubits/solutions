#include <cstdio>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    int mday = 2000000000, mjunk = 2000000000;
    for (int i = 0; i < k; i++) {
        int ij;
        scanf("%d", &ij);
        if (mjunk > ij) {
            mjunk = ij;
            mday = i;
        }
    }
    printf("%d\n", mday);
    return 0;
}
