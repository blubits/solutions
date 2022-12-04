#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int b, br, bs, a, as, ans;
    scanf("%d %d %d %d %d", &b, &br, &bs, &a, &as);
    int bm = (br - b) * bs;
    for (int am = 0; am <= bm; am += as) a++;
    printf("%d\n", a);
}
