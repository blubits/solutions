#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, c = 0;
    vector<int> base;
    vector<int> base_sorted;
    vector<int> other;
    while (scanf("%d", &n) && n != 0) {
        if (c != 0) printf("\n");
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            base.push_back(k);
            base_sorted.push_back(k);
        }
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            other.push_back(k);
        }
        sort(base_sorted.begin(), base_sorted.end());
        sort(other.begin(), other.end());
        for (int i = 0; i < n; i++) {
            base[i] =
                distance(base_sorted.begin(),
                         find(base_sorted.begin(), base_sorted.end(), base[i]));
        }
        for (auto k : base) {
            printf("%d\n", other[k]);
        }
        base.clear();
        base_sorted.clear();
        other.clear();
        c++;
    }
    return 0;
}
