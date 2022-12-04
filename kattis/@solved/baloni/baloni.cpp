#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int k;
    scanf("%d", &k);
    int hts[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &hts[i]);
    }
    int arrows = 0, hits = 0;
    while (hits != k) {
        for (int start_i = 0; start_i < k; start_i++) {
            if (hts[start_i] > 0) {
                arrows++;
                int curr_ht = hts[start_i];
                for (int i = start_i; i < k; i++) {
                    if (hts[i] == curr_ht) {
                        hts[i] = 0;
                        curr_ht--;
                        hits++;
                    }
                    if (curr_ht <= 0) break;
                }
            }
        }
    }
    printf("%d\n", arrows);
}
