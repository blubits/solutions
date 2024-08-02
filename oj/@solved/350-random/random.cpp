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

int Z, L, I, M;

int succ(int v) {
    return ((Z * v) + I) % M;
}

int find_cycle(int x) {

	int a = x, b = x;
	do {
		a = succ(a);
		b = succ(succ(b));
	} while (a != b);
	
	// Find mu (start of cycle)
	a = x; // rewind
	while (a != b) {
		a = succ(a);
		b = succ(b);
	}
	int mu = a;
	
	// Find lambda (length of cycle)
	int lambda = 1;
	b = succ(b);
	while (a != b) {
		b = succ(b);
		lambda++;
	}

    return lambda;
}



int main() {
    int T = 1;
    while (cin >> Z >> I >> M >> L && !(Z + L + I + M == 0)) {
        printf("Case %d: %d\n", T++, find_cycle(L));
    }
    return 0;
}