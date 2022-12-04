#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

void printarr(ll arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

int main() {
    int t;
    scanf("%d", &t);
    int a = 1 << t;
    // initialize tree
    ll tree[2 * a], lost[a], won[a];
    tree[0] = -1;
    for (int i = 0; i < a; i++) {
        scanf("%lld", &tree[a + i]);
    }
    int clevel = t, l = a, r = 2 * a;
    while (clevel != 1) {
        // "move up"
        for (int i = l; i < r; i += 4) {
            /**
             *    *       *
             *   / \     / \
             *  a   b   c   d
             */
            int a = i, b = i + 1, c = i + 2, d = i + 3;
            int pab = parent(a), pcd = parent(c);
            // max/min of left
            int minl = min(tree[a], tree[b]), maxl = max(tree[a], tree[b]);
            int minr = min(tree[c], tree[d]), maxr = max(tree[c], tree[d]);
            tree[pab] = maxl + minr;
            tree[pcd] = maxr + minl;
            lost[pab] = minr;
            lost[pcd] = minl;
            won[pab] = maxl;
            won[pcd] = maxr;
        }
        clevel--;
        l /= 2;
        r /= 2;
    }
    tree[1] = max(tree[2], tree[3]);
    lost[0] = lost[1] = 0;

    // main algo: force a node to win
    for (int i = a; i < 2 * a; i++) {
        int level = t, l = a, r = 2 * a, opp;
        if (i % 2 == 0)
            opp = i + 1;
        else
            opp = i - 1;
        int vw = tree[i], vl = tree[opp];
        while (level != 1) {
            // printf("%d: %lld %lld\n", level, vw, vl);
            vw += lost[parent(i)];
            if (i % 4 == 2 || i % 4 == 3)
                vl += won[parent(opp) - 1];
            else
                vl += won[parent(opp) + 1];
            level--;
            l /= 2;
            r /= 2;
        }
        // printf("1: %lld %lld\n", vw, vl);
        if (i != a) printf(" ");
        if (vw > vl) {
            printf("0");
        } else {
            printf("%d", vl - vw + 1);
        }
    }
    printf("\n");
}
