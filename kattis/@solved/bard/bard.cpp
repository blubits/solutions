#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
    int v, e, s = 0;
    scanf("%d\n%d", &v, &e);
    vector<set<int>> songs(v);
    while (e--) {
        int vn;
        scanf("%d", &vn);
        vector<int> villagers(vn);
        bool bard_present = false;
        for (int i = 0; i < vn; i++) {
            scanf("%d", &villagers[i]);
            if (--villagers[i] == 0) {
                bard_present = true;
            }
        }
        if (bard_present) {
            for (auto vi : villagers) {
                songs[vi].insert(s);
            }
            s++;
        } else {
            set<int> all_known;
            for (auto vi : villagers) {
                for (auto s : songs[vi]) {
                    all_known.insert(s);
                }
            }
            for (auto vi : villagers) {
                songs[vi] = all_known;
            }
        }
    }
    for (int i = 0; i < v; i++) {
        if (songs[i].size() == s) {
            printf("%d\n", i + 1);
        }
    }
}
