#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int p, a, b, c, d;

double price(int k) { return p * (sin(a * k + b) + cos(c * k + d) + 2); }

int main() {
    int n;
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    double max_decline = 0, max_p = 0;
    for (int i = 1; i <= n; i++) {
        double p = price(i);
        if (max_p < p) max_p = p;
        if (p < max_p) {
            max_decline = max(max_decline, max_p - p);
        }
    }
    printf("%.10lf\n", max_decline);
}
