#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

class SegmentTree {
	private:
		int sz;
		
		// Change int -> T to change the operating set
		int identity; 
		vector<int> A;
		vector<int> val;

        // Stores the last winner in that range
        vector<int> update;
        vector<bool> lazy;

		int left(int idx) { return 2 * idx; }
		int right(int idx) { return 2 * idx + 1;}

        void propagate(int idx, int L, int R) {
            if (lazy[idx]) {
                //printf("P %d [%d %d]\n", idx, L, R);
                if (L == R) {
                    // Leaf node, no need to propagate down
                    A[L] = update[idx];
                    lazy[idx] = false;
                    return;
                }
                if (val[left(idx)] == -1) val[left(idx)] = update[idx];
                if (val[right(idx)] == -1) val[right(idx)] = update[idx];
                // Right and left nodes have been updated
                // It is now their responsibility to update
                // their children, if needed; we do this
                // by setting their lazy[] parameter
                if (update[left(idx)] == -1) update[left(idx)] = update[idx];
                if (update[right(idx)] == -1)  update[right(idx)] = update[idx];
                lazy[left(idx)] = lazy[right(idx)] = true;
                lazy[idx] = false;
                //print();
            }
        }

        // Range update from [i, j] to v on node idx with AOR [L, R].
        // Change return type from int -> T to change the operating set
        void range_update_rec(int idx, int L, int R, int i, int j, int v) {
            if (i > j) return;
            //printf("RU %d [%d %d] [%d %d] %d\n", idx, L, R, i, j, v);
            if (L == i && R == j) {
                if (val[idx] != -1) return;
                val[idx] = v;
                // Set it to propagate down
                lazy[idx] = true;
                update[idx] = v;
                return;
            }
            // If there's a lazy update here, propagate it down
            propagate(idx, L, R);
            // Otherwise, just do as before
            int m = (L + R) / 2;
            range_update_rec(left(idx), L, m, i, min(j, m), v),
            range_update_rec(right(idx), m + 1, R, max(i, m + 1), j, v);
        }

		int point_query_rec(int idx, int L, int R, int i) {
			if (L == R) {
                propagate(idx, L, R);
                return val[idx];
            }
            propagate(idx, L, R);
			int m = (L + R) / 2;
			if (i <= m)
				return point_query_rec(left(idx), L, m, i);
			else 
                return point_query_rec(right(idx), m + 1, R, i);
		}
		
	public:
		// Change to the correct identity value
		SegmentTree(int n) : A(n), val(4 * n, -1), update(4 * n, -1), lazy(4 * n), sz(n), identity(-1) {}

		// Change int v -> T v to change the operating set
		void range_update(int i, int j, int v) {
            //printf("RU %d %d %d\n", i, j, v);
			range_update_rec(1, 0, sz - 1, i, j, v);
		}

		// Change return type from int -> T to change the operating set
		int point_query(int i) {
			return point_query_rec(1, 0, sz - 1, i);
		}

        void print() {
            for (auto i: val) {
                if (i == -1) printf("X ");
                else printf("%d ", i);
            }
            printf("\n");
        }

};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    SegmentTree st(n);
    while (m--) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l--;
        r--;
        x--;
        st.range_update(l, x - 1, x);
        st.range_update(x + 1, r, x);
        //st.print();
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", st.point_query(i) + 1);
        //st.print();
    }
    printf("\n");
}