#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<ll> vll;

class PURQTree {
    private:
        vll tree;
    public:
        PURQTree(int n) : tree(n + 1) {}
        PURQTree(const vll &list) : tree(list.size() + 1) {
            for (int i = 1; i <= list.size(); i++) {
                tree[i] += list[i - 1];
                if (i + LSOne(i) <= list.size()) tree[i + LSOne(i)] += tree[i]; 
            }
        }
        ll query(int j) {
            ll sum = 0;
            for (; j; j -= LSOne(j)) {
                sum += tree[j];
            }
            return sum;
        }
        ll query(int i, int j) {
            return query(j) - query(i - 1);
        }
        void update(int i, int v) {
            for (; i < tree.size(); i += LSOne(i)) {
                tree[i] += v;
            }
        }
};

int main() {
    int T, i = 1;
    vector<ll> list;
    while (scanf(" %d", &T) && T) {
        if (i != 1) printf("\n");
        printf("Case %d:\n", i++);
        list.clear();
        list.assign(T, 0);
        for (int i = 0; i < T; i++) scanf("%lld", &list[i]);
        PURQTree purq(list);
        char command;
        while (scanf(" %c", &command) && command != 'E') {
            switch (command) {
                case 'S':
                    int x, r;
                    scanf(" %d %d", &x, &r);
                    purq.update(x, r - list[x - 1]);
                    list[x - 1] = r;
                    break;
                case 'M':
                    int ui, uj;
                    scanf(" %d %d", &ui, &uj);
                    printf("%d\n", purq.query(ui, uj));
                    break;
            }
        }
        scanf("%c", &command);
        scanf("%c", &command);
    }
    return 0;
}