#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t, x, ans = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        ans += pow(x / 10, x % 10);
    }
    printf("%d\n", ans);
    return 0;
}
