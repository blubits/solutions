#include <cstdio>

using namespace std;

int main() {
    int X, N, p, a;
    scanf("%d\n%d", &X, &N);
    a = X;
    while (N--) {
        scanf("%d", &p);
        a += X - p;
    }
    printf("%d\n", a);
}
