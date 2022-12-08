#include <cstdio>

using namespace std;

int main() {
    int x, y, quad;
    scanf("%d\n%d", &x, &y);
    if (x > 0 && y > 0)
        quad = 1;
    else if (x < 0 && y > 0)
        quad = 2;
    else if (x < 0 && y < 0)
        quad = 3;
    else
        quad = 4;
    printf("%d\n", quad);
    return 0;
}
