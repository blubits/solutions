#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    double x1, y1, x2, y2, p;
    while (scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &p) == 5 &&
           x1 != 0) {
        printf("%.10lf\n",
               pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1 / p));
    }
}
