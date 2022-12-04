#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    printf("Lumberjacks:\n");
    while (t--) {
        int x[10];
        for (int i = 0; i < 10; i++) scanf("%d", &x[i]);
        bool asc = true, desc = true;
        for (int i = 0; i < 9; i++) {
            if (x[i] > x[i + 1]) asc = false;
            if (x[i] < x[i + 1]) desc = false;
        }
        if (asc || desc)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
}
