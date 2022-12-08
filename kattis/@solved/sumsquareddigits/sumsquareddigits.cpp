#include <cstdio>

using namespace std;

typedef unsigned long long ull;

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        int c;
        ull b, n;
        scanf("%d %llu %llu", &c, &b, &n);
        ull ans = 0;
        while (n != 0) {
            ans += (n % b) * (n % b);
            n /= b;
        }
        printf("%d %llu\n", c, ans);
    }
    return 0;
}
