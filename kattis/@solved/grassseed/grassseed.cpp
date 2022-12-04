#include <cstdio>

using namespace std;

int main() {
    float c, l, w, ans = 0;
    int t;
    scanf("%f\n%d", &c, &t);
    while (t--) {
        scanf("%f %f", &l, &w);
        ans += l * w;
    }
    printf("%.8f\n", ans * c);
    return 0;
}
