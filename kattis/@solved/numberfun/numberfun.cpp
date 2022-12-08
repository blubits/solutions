#include <cstdio>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    while (k--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        bool possible = false;
        if (a + b == c) possible = true;
        if (a - b == c) possible = true;
        if (b - a == c) possible = true;
        if (a * b == c) possible = true;
        if (a % b == 0 && a / b == c) possible = true;
        if (b % a == 0 && b / a == c) possible = true;
        if (possible)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
