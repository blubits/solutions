#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int k, c = 1;
    while (scanf("%d", &k) && k != 0) {
        int a[k], average = 0;
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
            average += a[i];
        }
        average /= k;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += abs(average - a[i]);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", c++, ans / 2);
    }
    return 0;
}
