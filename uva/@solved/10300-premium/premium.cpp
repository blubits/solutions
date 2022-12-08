#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, sum = 0;
        scanf("%d", &n);
        while (n--) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            sum += a * c;
        }
        printf("%d\n", sum);
    }
    return 0;
}
