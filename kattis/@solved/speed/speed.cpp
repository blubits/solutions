#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    vector<int> dist(n), vel(n);
    int min_c = 100000000;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &dist[i], &vel[i]);
        min_c = min(min_c, vel[i]);
    }
    min_c = -min_c;
    // BSTA
    double lo = min_c, hi = 1e10;
    while (abs(hi - lo) > 1e-8) {
        double mid = (hi + lo) / 2.0;
        // calculate t
        double t_calc = 0;
        for (int i = 0; i < n; i++) {
            t_calc += double(dist[i]) / (vel[i] + mid);
        }
        // printf("%lf %lf %lf: %lf\n", lo, mid, hi, t_calc);
        if (t_calc == t)
            break;
        else if (t_calc > t) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.9lf\n", (hi + lo) / 2.0);
}
