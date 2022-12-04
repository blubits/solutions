#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    x = (x / 100) + ((x % 100) - (x % 10)) + (100 * (x % 10));
    y = (y / 100) + ((y % 100) - (y % 10)) + (100 * (y % 10));
    printf("%d\n", max(x, y));
    return 0;
}
