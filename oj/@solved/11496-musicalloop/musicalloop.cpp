#include <cstdio>

using namespace std;

int main() {
    int k;
    while (scanf("%d", &k) && k != 0) {
        int a[k];
        for (int i = 0; i < k; i++) scanf("%d", &a[i]);
        int p = 0;
        for (int i = 0; i < k; i++) {
            int l = i - 1;
            if (l == -1) l = k - 1;
            int r = i + 1;
            if (r == k) r = 0;
            if (a[l] < a[i] && a[r] < a[i]) p++;
            if (a[l] > a[i] && a[r] > a[i]) p++;
        }
        printf("%d\n", p);
    }
    return 0;
}
