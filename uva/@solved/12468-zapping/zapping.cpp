#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int x, y;
    while (1) {
        scanf("%d %d", &x, &y);
        if (x == -1 && y == -1) break;
        printf("%d\n", min(abs(y - x), 100 - abs(x - y)));
    }
    return 0;
}
