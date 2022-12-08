#include <cstdio>

using namespace std;

int main() {
    int a, b;
    int ans;
    scanf("%d %d", &a, &b);
    if (a % 4 == 2) {
        ans = a / 2;
    } else if (a % 4 == 0 and b == 1) {
        ans = a / 2;
    } else {
        ans = 0;
    }
    printf("%d\n", ans);
    return 0;
}
