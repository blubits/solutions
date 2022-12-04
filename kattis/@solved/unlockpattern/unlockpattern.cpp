#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int x[9], y[9];
    double dist = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int k;
            scanf("%d", &k);
            x[k - 1] = i;
            y[k - 1] = j;
        }
    }
    for (int i = 1; i < 9; i++) {
        dist += hypot(x[i] - x[i - 1], y[i] - y[i - 1]);
    }
    printf("%.10lf\n", dist);
    return 0;
}
