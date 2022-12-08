#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double x, conv = 1000.0 * (5280.0 / 4854.0);
    scanf("%lf", &x);
    printf("%d\n", (int)(round(x * conv)));
    return 0;
}
