#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    while (1) {
        int t;
        scanf("%d\n", &t);
        if (t == 0) break;
        int d_idx = -100000000, r_idx = -100000000, m = 500000000;
        bool z_found = false;
        char c;
        for (int i = 0; i < t; i++) {
            scanf("%c", &c);
            if (z_found) continue;
            if (c == '.') continue;
            if (c == 'Z') {
                m = 0;
                z_found = true;
            } else if (c == 'D') {
                d_idx = i;
                m = min(m, abs(d_idx - r_idx));
            } else if (c == 'R') {
                r_idx = i;
                m = min(m, abs(d_idx - r_idx));
            }
        }
        printf("%d\n", m);
    }
    return 0;
}
