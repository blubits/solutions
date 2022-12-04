#include <cmath>
#include <cstdio>

#define ERROR 1e-16

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    double e = 0;
    long long int fact = 1;
    for (int i = 0; i <= k; i++) {
        double est = 1.0 / fact;
        if (abs(est) < ERROR) {
            break;
        } else {
            e += est;
        }
        fact *= (i + 1);
    }
    printf("%.16lf\n", e);
    return 0;
}
