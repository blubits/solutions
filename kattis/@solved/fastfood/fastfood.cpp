#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int p, s;
        scanf("%d %d\n", &p, &s);
        bool needed[p][s];
        int value[p];
        int have[s];
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < s; j++) {
                needed[i][j] = false;
            }
        }
        for (int i = 0; i < p; i++) {
            int ns;
            scanf("%d", &ns);
            while (ns--) {
                int st;
                scanf("%d", &st);
                needed[i][st - 1] = true;
            }
            scanf("%d", &value[i]);
        }
        for (int i = 0; i < s; i++) {
            scanf("%d", &have[i]);
        }
        int totalval = 0;
        for (int i = 0; i < p; i++) {
            int min_sr = 10000;
            for (int j = 0; j < s; j++) {
                if (needed[i][j]) min_sr = min(min_sr, have[j]);
            }
            totalval += min_sr * value[i];
        }
        printf("%d\n", totalval);
    }
    return 0;
}
