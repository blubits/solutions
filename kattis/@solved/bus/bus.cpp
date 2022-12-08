#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a;
        scanf("%d", &a);
        unsigned long long int ans = (1 << a) - 1;
        printf("%llu\n", ans);
    }
    return 0;
}
