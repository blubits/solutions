#include <algorithm>
#include <cstdio>
#include <iterator>

using namespace std;

int main() {
    int a[4];
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
    sort(begin(a), end(a));
    printf("%d\n", a[0] * a[2]);
    return 0;
}
