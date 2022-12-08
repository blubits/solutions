#include <iostream>
#define PI 3.1415926
using namespace std;

int main() {
    double m, n, r;
    cin >> m >> n >> r;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double r_outer = (r / n) * y1;
    double r_inner = (r / n) * y2;
    // strategy 1: regular
    // (1) go across y
    double y_dist = (r / n) * abs(y1 - y2);
    // (2) go across x
    double c_inner = PI * r_inner;
    double x_dist = (c_inner / m) * abs(x1 - x2);
    // strategy 2: moving along radiuses always
    double distance = r * ((y1 / n) + (y2 / n));
    // strategy 3: regular, reverse
    // (1) go across x
    double c_outer = PI * r_outer;
    double x_dist_alt = (c_outer / m) * abs(x1 - x2);
    // (1) go across y
    double y_dist_alt = (r / n) * abs(y1 - y2);
    printf("%.15f",
           min(distance, min(x_dist_alt + y_dist_alt, x_dist + y_dist)));
    return 0;
}
