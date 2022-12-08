#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int t, x;
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d\n", &x);
        if (abs(x % 2) == 1)
            printf("%d is odd\n", x);
        else
            printf("%d is even\n", x);
    }
    return 0;
}
