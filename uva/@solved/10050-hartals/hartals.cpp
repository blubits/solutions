#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        bool strike[n + 1];
        for (int i = 0; i <= n; i++) strike[i] = false;
        int p, k;
        scanf("%d", &p);
        while (p--) {
            scanf("%d", &k);
            for (int i = 1; i <= n; i++) {
                if (i % k == 0) strike[i] = true;
            }
        }
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (strike[i] && !(i % 7 == 6 || i % 7 == 0)) c++;
        }
        printf("%d\n", c);
    }
    return 0;
}
