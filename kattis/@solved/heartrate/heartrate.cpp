#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int b;
        double p;
        scanf("%d %lf", &b, &p);
        printf("%.4lf %.4lf %.4lf\n", (60 * (b - 1)) / p, (60 * b) / p,
               (60 * (b + 1)) / p);
    }
    return 0;
}
