#include <cmath>
#include <cstdio>

#define LOG3 log10(3)
#define LOG2 log10(2)

using namespace std;

int main() {
    int c = 1, k;
    while (scanf("%d", &k) == 1) {
        double ansk = ((k + 1) * LOG3) - (k * LOG2) + 1;
        int ans = ansk;
        printf("Case %d: %d\n", c++, ans);
    }
}
