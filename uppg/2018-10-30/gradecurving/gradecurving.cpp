#include <cmath>
#include <cstdio>

using namespace std;

double F(double x) { return 10.0 * sqrt(x); }

int main() {
    // note:
    // lim of repeated function application
    // is 10 * 10^1/2 * 10^1/4 * .... = 10^2 = 100
    // so if upper bound is 100, you can theoretically
    // apply the function infinite times
    int x, yl, yh;
    scanf("%d %d %d", &x, &yl, &yh);
    int t = 0, tl = -100, th = -100;
    double fx = x;
    bool in_interval = false;
    while (true) {
        if (yl <= ceil(fx) && ceil(fx) <= yh && !in_interval) {
            in_interval = true;
            tl = t;
            if (yh == 100) {
                in_interval = false;
                th = -1;
                break;
            }
        }
        if (ceil(fx) >= yh) {
            if (in_interval) {
                in_interval = false;
                if (ceil(fx) > yh)
                    th = t - 1;
                else
                    th = t;
            } else {
                tl = -100;
                th = -100;
            }
            break;
        }
        fx = F(fx);
        t++;
    }
    if (th == -1) {
        printf("%d inf\n", tl, th);
    } else if (th == -100 && tl == -100) {
        printf("impossible\n");
    } else {
        printf("%d %d\n", tl, th);
    }
    return 0;
}
