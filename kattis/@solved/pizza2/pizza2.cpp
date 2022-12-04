#include <cstdio>

using namespace std;

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    double o = r * r, i = (r - c) * (r - c);
    printf("%.10lf\n", 100.0 * (i / o));
    return 0;
}
