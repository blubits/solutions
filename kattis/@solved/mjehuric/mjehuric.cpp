#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int k;
    while (scanf("%d", &k) == 1) v.push_back(k);
    // bubble sort
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                iter_swap(v.begin() + j, v.begin() + j + 1);
                for (int k = 0; k < v.size(); k++) {
                    if (k != 0) printf(" ");
                    printf("%d", v[k]);
                }
                printf("\n");
            }
        }
    }
}
