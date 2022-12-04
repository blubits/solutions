#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        int hts[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &hts[i]);
        }
        int hi = 0, lo = 0;
        for (int i = 1; i < n; i++) {
            if (hts[i - 1] < hts[i])
                hi++;
            else if (hts[i - 1] > hts[i])
                lo++;
        }
        printf("Case %d: %d %d\n", i, hi, lo);
    }
    return 0;
}
