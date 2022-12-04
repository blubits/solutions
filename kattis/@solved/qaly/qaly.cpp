#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    double total = 0, q, y;
    while (t--) {
        scanf("%lf %lf", &q, &y);
        total += q * y;
    }
    printf("%.8lf\n", total);
    return 0;
}
