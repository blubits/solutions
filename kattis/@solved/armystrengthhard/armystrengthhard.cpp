#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int g, mg, max_g = 0, max_mg = 0;
        scanf("%d %d", &g, &mg);
        while (g--) {
            int gi;
            scanf("%d", &gi);
            max_g = max(max_g, gi);
        }
        while (mg--) {
            int mgi;
            scanf("%d", &mgi);
            max_mg = max(max_mg, mgi);
        }
        if (max_mg > max_g) {
            printf("MechaGodzilla\n");
        } else {
            printf("Godzilla\n");
        }
    }
    return 0;
}
