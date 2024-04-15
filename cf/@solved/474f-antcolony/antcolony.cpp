#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b) { 
    if (a == -1) return b;
    if (b == -1) return a;
    return b == 0 ? a : gcd(b, a%b); 
}

class SegmentTreeGCD {
	private:
		int sz;
		
		// Change int -> T to change the operating set
		int identity; 
		vector<ll> A;
		vector<ll> val;

		int left(int idx) { return 2 * idx; }
		int right(int idx) { return 2 * idx + 1;}

		// Change int -> T to change the operating set
		// Change function to change the operation
		ll combine(ll lval, ll rval) {
			return gcd(lval, rval);
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
		ll range_query_rec(int idx, int L, int R, int i, int j) {
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
		SegmentTreeGCD(int n) : A(n), val(4 * n), sz(n), identity(-1) {}

		SegmentTreeGCD(const vector<ll> &L) : SegmentTreeGCD(L.size()) {
			A = L;
			build_rec(1, 0, sz - 1);
		}

		// Change int v -> T v to change the operating set
		void point_update(int i, int v) {
			point_update_rec(1, 0, sz - 1, i, v);
		}

		// Change return type from int -> T to change the operating set
		ll range_query(int i, int j) {
			return range_query_rec(1, 0, sz - 1, i, j);
		}

};

class SegmentTreeMin {
	private:
		int sz;
		
		// Change int -> T to change the operating set
		ll identity; 
		vector<ll> A;
		vector<ll> val;

		int left(int idx) { return 2 * idx; }
		int right(int idx) { return 2 * idx + 1;}

		// Change int -> T to change the operating set
		// Change function to change the operation
		ll combine(ll lval, ll rval) {
			return min(lval, rval);
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
		ll range_query_rec(int idx, int L, int R, int i, int j) {
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
		SegmentTreeMin(int n) : A(n), val(4 * n), sz(n), identity(4000000000) {}

		SegmentTreeMin(const vector<ll> &L) : SegmentTreeMin(L.size()) {
			A = L;
			build_rec(1, 0, sz - 1);
		}

		// Change int v -> T v to change the operating set
		void point_update(int i, int v) {
			point_update_rec(1, 0, sz - 1, i, v);
		}

		// Change return type from int -> T to change the operating set
		ll range_query(int i, int j) {
			return range_query_rec(1, 0, sz - 1, i, j);
		}

};

vector<ll> colony;
vector<pair<int, int>> occ;

int main() {
    int n;
    cin >> n;
    colony.resize(n);
    for (int i = 0; i < n; i++) {
		cin >> colony[i];
		occ.push_back({colony[i], i});
	}
	sort(occ.begin(), occ.end());
    SegmentTreeGCD stgcd(colony);
    SegmentTreeMin stmin(colony);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        ll rq_gcd = stgcd.range_query(l - 1, r - 1), rq_min = stmin.range_query(l - 1, r - 1);
        ll amnt = r - l + 1;
		auto ub = upper_bound(occ.begin(), occ.end(), make_pair(int(rq_min), r - 1));
		auto lb = lower_bound(occ.begin(), occ.end(), make_pair(int(rq_min), l - 1));
        ll nvalues = ub - lb;
		if (rq_gcd == rq_min) {
            cout << amnt - nvalues;
        } else {
            cout << amnt;
        }
        cout << endl;
    }
    return 0;
}