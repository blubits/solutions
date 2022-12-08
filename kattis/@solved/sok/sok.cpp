#include <cstdio>

using namespace std;

int main() {
    int bought[3], required[3];
    double ratio[3];
    for (int i = 0; i < 3; i++) scanf("%d", &bought[i]);
    for (int i = 0; i < 3; i++) scanf("%d", &required[i]);
    // find limiting factor
    double min_r = 10000000000;
    for (int i = 0; i < 3; i++) {
        ratio[i] = double(bought[i]) / double(required[i]);
        if (ratio[i] < min_r) min_r = ratio[i];
    }
    for (int i = 0; i < 3; i++) {
        if (i != 0) printf(" ");
        printf("%.6lf", bought[i] - (required[i] * min_r));
    }
    printf("\n");
    return 0;
}
