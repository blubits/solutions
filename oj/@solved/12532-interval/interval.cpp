#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
	private:
		int sz;
		
		// Change int -> T to change the operating set
		int identity; 
		vector<int> A;
		vector<int> val;

		int left(int idx) { return 2 * idx; }
		int right(int idx) { return 2 * idx + 1;}

		// Change int -> T to change the operating set
		// Change function to change the operation
		int combine(int lval, int rval) {
			return lval * rval;
		}
		
		void build_rec(int idx, int L, int R) {
			if (L == R) {
				val[idx] = A[L]; // = A[R]
				return;
			}
			int m = (L + R) / 2;
			build_rec(left(idx), L, m);
			build_rec(right(idx), m + 1, R);
			val[idx] = combine(val[left(idx)], val[right(idx)]);
		}

		// Point update A[i] = v on node idx with AOR [L, R].
		// Change int v -> T v to change the operating set
		void point_update_rec(int idx, int L, int R, int i, int v) {
			if (L == R) {
				A[i] = v;
				val[idx] = v;
				return;
			}
			int m = (L + R) / 2;
			if (L <= i && i <= m) {
				point_update_rec(left(idx), L, m, i, v);
			}
			if (m + 1 <= i && i <= R) {
				point_update_rec(right(idx), m + 1, R, i, v);
			}
			val[idx] = combine(val[left(idx)], val[right(idx)]);
		}

		// Range query from [i, j] on node idx with AOR [L, R].
		// Change return type from int -> T to change the operating set
		int range_query_rec(int idx, int L, int R, int i, int j) {
			if (i > j) return identity;
			if (L == i && R == j) return val[idx];
			int m = (L + R) / 2;
			return combine(
				range_query_rec(left(idx), L, m, i, min(j, m)),
			    range_query_rec(right(idx), m + 1, R, max(i, m + 1), j)
			);
		}
		
	public:
		// Change to the correct identity value
		SegmentTree(int n) : A(n), val(4 * n), sz(n), identity(1) {}

		SegmentTree(const vector<int> &L) : SegmentTree(L.size()) {
			A = L;
			build_rec(1, 0, sz - 1);
		}

		// Change int v -> T v to change the operating set
		void point_update(int i, int v) {
			point_update_rec(1, 0, sz - 1, i, v);
		}

		// Change return type from int -> T to change the operating set
		int range_query(int i, int j) {
			return range_query_rec(1, 0, sz - 1, i, j);
		}

};

vector<int> L;

int main() {
    int N, K;
    while (scanf("%d %d", &N, &K) != EOF) {
        L.clear();
        L.resize(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &L[i]);
            L[i] = (L[i] > 0) ? 1 : ((L[i] < 0) ? -1 : 0);
        }
        SegmentTree st(L);
        while (K--) {
            char c;
            int a, b;
            scanf(" %c %d %d", &c, &a, &b);
            if (c == 'C') {
                st.point_update(a - 1, (b > 0) ? 1 : ((b < 0) ? -1 : 0));
            } else {
                int val = st.range_query(a - 1, b - 1);
                printf("%c", (val > 0) ? '+' : ((val < 0) ? '-' : '0'));
            }
        }
        printf("\n");
    }
}