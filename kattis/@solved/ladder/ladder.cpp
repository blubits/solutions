#include <cmath>
#include <cstdio>

#define PI 3.14159265

using namespace std;

int main() {
    int h, v;
    scanf("%d %d\n", &h, &v);
    printf("%d\n", (int)ceil(h / sin(v * PI / 180)));
    return 0;
}
