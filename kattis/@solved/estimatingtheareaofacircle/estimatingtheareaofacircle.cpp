#include <cmath>
#include <cstdio>

#define PI atan(1.0) * 4

using namespace std;

int main() {
    int tot, in;
    double r;
    while (scanf("%lf %d %d", &r, &tot, &in) &&
           !(r == 0 && tot == 0 && in == 0)) {
        double actual = PI * r * r;
        double estimate = 4 * r * r * (double(in) / double(tot));
        printf("%.8lf %.8lf\n", actual, estimate);
    }
    return 0;
}
