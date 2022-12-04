#include <cstdio>

using namespace std;

int main() {
    int h, w, b;
    scanf("%d %d %d", &h, &w, &b);
    int cr = 0, cl = 0;
    bool buildable = true;
    while (b--) {
        int bi;
        scanf("%d", &bi);
        if (cl + bi > w) {
            buildable = false;
            break;
        } else if (cl + bi == w) {
            cl = 0;
            cr++;
        } else {
            cl += bi;
        }
    }
    if (buildable)
        printf("YES\n");
    else
        printf("NO\n");
}
