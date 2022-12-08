#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int na = b, nb = a % b;
        a = na;
        b = nb;
    }
    return a;
}

int main() {
    int t, b;
    scanf("%d\n%d", &t, &b);
    t--;
    while (t--) {
        int a;
        scanf("%d", &a);
        int g = gcd(a, b);
        printf("%d/%d\n", b / g, a / g);
    }
    return 0;
}
