#include <cstdio>

using namespace std;

int main() {
    int t, i, sum = 0, n = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &i);
        if (i >= 0) {
            sum += i;
            n++;
        }
    }
    printf("%.16lf\n", (double)(sum) / (double)(n));
    return 0;
}
