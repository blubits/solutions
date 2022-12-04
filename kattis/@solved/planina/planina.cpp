#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int x;
    scanf("%d", &x);
    x = exp2(x) + 1;
    printf("%d\n", x * x);
}
