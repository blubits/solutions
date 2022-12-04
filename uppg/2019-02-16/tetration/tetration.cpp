#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    double k;
    scanf("%lf", &k);
    printf("%.6lf\n", pow(k, 1.0 / k));
}
