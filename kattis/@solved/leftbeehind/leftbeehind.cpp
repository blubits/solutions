#include <cstdio>

using namespace std;

int main() {
    int sweet, sour;
    while (scanf("%d %d", &sweet, &sour) && !(sweet == 0 && sour == 0)) {
        if (sweet + sour == 13)
            printf("Never speak again.\n");
        else if (sweet > sour)
            printf("To the convention.\n");
        else if (sour > sweet)
            printf("Left beehind.\n");
        else
            printf("Undecided.\n");
    }
    return 0;
}
