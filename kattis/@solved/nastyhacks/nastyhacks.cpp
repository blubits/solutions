#include <cstdio>

using namespace std;

int main() {
    int t, r, e, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &r, &e, &c);
        if (r < e - c)
            printf("advertise\n");
        else if (r == e - c)
            printf("does not matter\n");
        else
            printf("do not advertise\n");
    }
    return 0;
}
