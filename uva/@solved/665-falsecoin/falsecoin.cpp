#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, c;
        scanf("%d %d", &n, &c);
        bool is_false[n];
        for (int i = 0; i < n; i++) is_false[i] = true;
        while (c--) {
            char k;
            int a;
            scanf("%d", &a);
            int left[a], right[a];
            bool weighed[n];
            for (int i = 0; i < n; i++) weighed[i] = false;
            for (int i = 0; i < a; i++) {
                scanf("%d", &left[i]);
                weighed[left[i] - 1] = true;
            }
            for (int i = 0; i < a; i++) {
                scanf("%d", &right[i]);
                weighed[right[i] - 1] = true;
            }
            scanf("\n%c\n", &k);
            if (k == '<' || k == '>') {
                for (int i = 0; i < n; i++) {
                    if (!weighed[i]) is_false[i] = false;
                }
            } else if (k == '=') {
                for (int i = 0; i < n; i++) {
                    if (weighed[i]) is_false[i] = false;
                }
            }
            // printf("%c ", k);
            // for (int i = 0; i < n; i++) printf("%c", weighed[i] ? 'w' : '-');
            // printf("\n  ");
            // for (int i = 0; i < n; i++) printf("%c", is_false[i] ? 'f' :
            // 'g'); printf("\n");
        }
        int fcoin = -1;
        for (int i = 0; i < n; i++) {
            if (is_false[i] && fcoin != -1) {
                fcoin = -1;
                break;
            } else if (is_false[i] && fcoin == -1) {
                fcoin = i;
            }
        }
        printf("%d\n", fcoin + 1);
        if (t != 0) printf("\n");
    }
}
