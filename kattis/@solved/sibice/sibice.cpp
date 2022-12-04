#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n, w, h;
    scanf("%d %d %d", &n, &w, &h);
    float max = sqrt(w * w + h * h);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (x <= max)
            printf("DA\n");
        else
            printf("NE\n");
    }
    return 0;
}
