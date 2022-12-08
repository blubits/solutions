#include <cstdio>

using namespace std;

bool valid(int comb) {
    bool app[10] = {false};
    int oc = comb;
    while (comb != 0) {
        int d = comb % 10;
        if (app[d])
            return false;
        else
            app[d] = true;
        if (d == 0 || oc % d != 0) return false;
        comb /= 10;
    }
    return true;
}

int main() {
    int l, h, c = 0;
    scanf("%d %d", &l, &h);
    for (int i = l; i <= h; i++) {
        if (valid(i)) c++;
    }
    printf("%d\n", c);
    return 0;
}
