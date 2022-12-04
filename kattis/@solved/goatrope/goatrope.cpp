#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int x, y, x1, y1, x2, y2;
    scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);
    double m = 0;
    if (x < x1 && y < y1)
        m = hypot(x - x1, y - y1);
    else if (x1 < x && x < x2 && y < y1)
        m = abs(y - y1);
    else if (x > x2 && y < y1)
        m = hypot(x - x2, y - y1);
    else if (x > x2 && y1 < y && y < y2)
        m = abs(x - x2);
    else if (x > x2 && y > y2)
        m = hypot(x - x2, y - y2);
    else if (x1 < x && x < x2 && y > y2)
        m = abs(y - y2);
    else if (x < x1 && y > y2)
        m = hypot(x - x1, y - y2);
    else if (x < x1 && y1 < y && y < y2)
        m = abs(x - x1);
    printf("%.8lf\n", m);
    return 0;
}
