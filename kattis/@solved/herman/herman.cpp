#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    const double pi = atan(1) * 4;
    int r;
    scanf("%d", &r);
    printf("%.6lf\n%.6lf\n", pi * r * r, 2.0 * r * r);
    return 0;
}
