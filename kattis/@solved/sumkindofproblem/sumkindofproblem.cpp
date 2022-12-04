#include <cstdio>

using namespace std;

int main() {
    int s1[20000] = {0}, s2[20000] = {0}, s3[20000] = {0};
    for (int i = 1; i <= 10000; i++) {
        s1[i] = i + s1[i - 1];
        s3[i] = (2 * i) + s3[i - 1];
        s2[i] = (2 * i - 1) + s2[i - 1];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int c, n;
        scanf("%d %d", &c, &n);
        printf("%d %d %d %d\n", c, s1[n], s2[n], s3[n]);
    }
    return 0;
}
