#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    double const_a, const_b;
    double ans_x, ans_y, ans;
    double a, b, c;
    double n, x, y;
    while (1) {
        cin >> n;
        if (!n) return 0;
        cin >> x >> y;
        ans = 0;
        const_a = 0;
        const_b = 0;
        while (n) {
            cin >> a >> b >> c;
            if (const_b == 0 && const_a == 0) {
                const_b = b;
                const_c = c;
                ans_y = a;
                continue;
            } else {
                if (const_b > x)
                    const_b = ((abs(const_b - x) / ans_y) * (y - a)) + x;
                else
                    const_b = ((abs(const_b - x) / ans_y) * (y - a)) - x;
                if (b <= const_c)
                    const_b = max(b, const_b);
                else {
                }
                if (c >= const_b)
                    const_c = min(c, const_c);
                else {
                }
            }
            n--;
        }
        printf("%.10f\n", ans);
    }
}
