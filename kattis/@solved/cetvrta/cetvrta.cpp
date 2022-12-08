#include <cstdio>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d\n%d %d\n%d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    if (x1 != x2)
        x4 = (2 * x1 + 2 * x2) - (x1 + x2 + x3);
    else if (x1 != x3)
        x4 = (2 * x1 + 2 * x3) - (x1 + x2 + x3);
    else if (x2 != x3)
        x4 = (2 * x2 + 2 * x3) - (x1 + x2 + x3);
    if (y1 != y2)
        y4 = (2 * y1 + 2 * y2) - (y1 + y2 + y3);
    else if (y1 != y3)
        y4 = (2 * y1 + 2 * y3) - (y1 + y2 + y3);
    else if (y2 != y3)
        y4 = (2 * y2 + 2 * y3) - (y1 + y2 + y3);
    printf("%d %d\n", x4, y4);
}
