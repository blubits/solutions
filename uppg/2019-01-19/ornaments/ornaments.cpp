#include <cmath>
#include <cstdio>

#define PI atan(1.0) * 4.0

using namespace std;

int main() {
    int r, h, s;
    while (scanf("%d %d %d", &r, &h, &s) && (r || h || s)) {
        double top = 2 * sqrt(h * h - r * r);
        double sub_ang = PI - acos(double(r) / double(h));
        double bottom = 2.0 * r * sub_ang;
        double string = (top + bottom) * ((100 + s) / 100.0);
        printf("%.2lf\n", string);
    }
    return 0;
}
