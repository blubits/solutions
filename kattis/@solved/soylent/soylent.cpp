#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", int(ceil(n / 400.0)));
    }
    return 0;
}
