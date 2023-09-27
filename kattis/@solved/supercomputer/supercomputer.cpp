#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
using namespace std;

typedef vector<int> vi;

class BinaryIndexTree {
	
private:
	vi ft;
public:
	BinaryIndexTree(int m) { ft.assign(m+1, 0); }
	BinaryIndexTree(vi &A) {
		// f is zero-indexed
		int m = (int) A.size();
		ft.assign(m + 1, 0);
		for (int i = 1; i <= m; ++i) {
			ft[i] += A[i];
			if (i + LSOne(i) <= m) ft[i + LSOne(i)] += ft[i];
		}
	}

	int query(int j) {
		int sum = 0;
		for (; j; j -= LSOne(j))
			sum += ft[j];
		return sum;
	}
	
	int query(int i, int j) { 
		return query(j) - query(i-1); 
	} 

	void update(int i, int v) {
		for (; i < ft.size(); i += LSOne(i))
			ft[i] += v;
	}
};

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    BinaryIndexTree bt(N);
    vi bta(N + 1);
    while (K--) {
        char q;
        scanf(" %c", &q);
        if (q == 'F') {
            int i;
            scanf(" %d", &i);
            if (bta[i]) {
                bta[i] = 0;
                bt.update(i, -1);
            } else {
                bta[i] = 1;
                bt.update(i, 1);
            }
        } else {
            int i, j;
            scanf(" %d %d", &i, &j);
            printf("%d\n", bt.query(i, j));
        }
    }   
    return 0;
}