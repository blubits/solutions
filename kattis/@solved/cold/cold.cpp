#include <cstdio>

using namespace std;

int main() {
    int n, t, cold = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        if (t < 0) cold++;
    }
    printf("%d\n", cold);
    return 0;
}
