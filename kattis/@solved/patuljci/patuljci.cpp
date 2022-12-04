#include <cstdio>

using namespace std;

int main() {
    int hats[9], sum = 0, dop1, dop2;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &hats[i]);
        sum += hats[i];
    }
    bool broke = false;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - hats[i] - hats[j] == 100) {
                dop1 = i;
                dop2 = j;
                broke = true;
                break;
            }
        }
        if (broke) break;
    }
    for (int i = 0; i < 9; i++)
        if (i != dop1 && i != dop2) printf("%d\n", hats[i]);
    return 0;
}
