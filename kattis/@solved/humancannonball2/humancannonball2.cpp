#include <cmath>
#include <cstdio>
#define PI 3.1415926
#define GRAVITY 9.81

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        double v0, theta, x1, h1, h2;
        scanf("%lf %lf %lf %lf %lf", &v0, &theta, &x1, &h1, &h2);
        double t = x1 / (v0 * cos(theta * (PI / 180)));
        double y = v0 * t * sin(theta * (PI / 180)) - 0.5 * GRAVITY * t * t;
        if (h1 + 1 <= y && y <= h2 - 1) {
            printf("Safe\n");
        } else {
            printf("Not Safe\n");
        }
    }
    return 0;
}
