#include <algorithm>
#include <cstdio>

using namespace std;

int digital_sum(int x) {
    int s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    int l, d, x;
    scanf("%d\n%d\n%d", &l, &d, &x);
    int mn = d + 1, mx = l - 1;
    for (int i = l; i <= d; i++) {
        int ds = digital_sum(i);
        if (ds == x) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    printf("%d\n%d\n", mn, mx);
    return 0;
}
