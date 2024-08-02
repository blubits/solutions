#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int n;
vector<int> succ;
vector<vector<int>> adj_t;

// Pre-cached answer.
vector<int> ans;

void fill_tree(int v, int dist) {
	for (auto n: adj_t[v]) {
		if (ans[n] != -1) continue;
		ans[n] = dist + 1;
		fill_tree(n, dist + 1);
	}
}

void find_cycle(int x) {

	int a = x, b = x;
	do {
		a = succ[a];
		b = succ[succ[b]];
	} while (a != b);
	
	// Find mu (start of cycle)
	a = x; // rewind
	while (a != b) {
		a = succ[a];
		b = succ[b];
	}
	int mu = a;
	
	// Find lambda (length of cycle)
	int lambda = 1;
	b = succ[b];
	while (a != b) {
		b = succ[b];
		lambda++;
	}

	// We know everything in the cycle has distance lambda. Pre-fill that
	int c = mu;
	do {
		ans[c] = lambda;
		c = succ[c];
	} while (c != mu);

	// Now pre-fill every tree that feeds into the cycle
	c = mu;
	do {
		fill_tree(c, lambda);
		c = succ[c];
	} while (c != mu);

}

int main() {
    scanf("%d", &n);
    succ.resize(n);
	ans.resize(n, -1);
	adj_t.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &succ[i]);
        succ[i]--;
		adj_t[succ[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) find_cycle(i);
    }
	for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    printf("\n");
    return 0;
}