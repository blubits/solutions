#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        int ans = abs((((((x * 567) / 9) + 7492) * 235) / 47) - 498);
        printf("%d\n", (ans / 10) % 10);
    }
    return 0;
}
