#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    unsigned long long int a;
    scanf("%llu", &a);
    printf("%.20lf\n", 4.0 * sqrt(a));
    return 0;
}
