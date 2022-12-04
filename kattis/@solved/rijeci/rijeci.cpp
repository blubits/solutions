#include <cstdio>

using namespace std;

int main() {
    int k, a = 1, b = 0;
    scanf("%d", &k);
    while (k--) {
        int na = b, nb = b + a;
        a = na;
        b = nb;
    }
    printf("%d %d\n", a, b);
    return 0;
}
