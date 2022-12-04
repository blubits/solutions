#include <cstdio>

using namespace std;

int main() {
    int n, s, r;
    scanf("%d %d %d", &n, &s, &r);
    int kayaks[n];
    for (int i = 0; i < n; i++) kayaks[i] = 1;
    while (s--) {
        int si;
        scanf("%d", &si);
        kayaks[si - 1] -= 1;
    }
    while (r--) {
        int ri;
        scanf("%d", &ri);
        kayaks[ri - 1] += 1;
    }
    for (int i = 0; i < n; i++) {
        if (kayaks[i] == 2) {
            if (i > 0 && kayaks[i - 1] == 0) {
                kayaks[i - 1] += 1;
                kayaks[i] -= 1;
            } else if (i < (n - 1) && kayaks[i + 1] == 0) {
                kayaks[i + 1] += 1;
                kayaks[i] -= 1;
            }
        }
    }
    int a = 0;
    for (int i = 0; i < n; i++)
        if (kayaks[i] == 0) a++;
    printf("%d\n", a);
}
