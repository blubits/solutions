#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> signs;

class SegmentTree {
    private:
        int n;
        int identity;
        vector<int> st;
        vector<int> data;

        int left(int idx) {return 2 * idx;}
        int right(int idx) {return 2 * idx + 1;}
        int parent(int idx) {return idx/2;}

        int combine(int lval, int rval) {
            return lval * rval;
        }

        void build(int i, int l, int r) {
            if (l == r) {
                st[i] = data[l];
                return;
            }
            int m = (l+r)/2;
            build(left(i), l, m);
            build(right(i), m+1, r);
            st[i] = combine(st[left(i)], st[right(i)]);
        }

        void point_update(int idx, int l, int r, int i, int v) {
            // printf("idx: %d\nl: %d\nr: %d\ni: %d\nv: %d\n", idx, l, r, i, v);
            if (l == r) {
                st[idx] = v;
                data[i] = v;
                return;
            }
            int m = (l+r)/2;
            if (l <= i && i <= m) {
                point_update(left(idx), l, m, i, v);
            } else if (m+1 <= i && i <= r) {
                point_update(right(idx), m+1, r, i, v);
            }
            st[idx] = combine(st[left(i)], st[right(i)]);
        }

        int range_query(int idx, int l, int r, int i, int j) {
            // printf("idx: %d\nl: %d\nr: %d\ni: %d\nj: %d\n", idx, l, r, i, j);
            if (i > j) return identity;
            if (l == i && r == j) return st[idx];
            int m = (l + r) / 2;
            return combine(
                range_query(left(idx), l, m, i, min(r, m)),
                range_query(right(idx), m+1, r, max(l, m+1), j)   
            );
        }
    public:
        SegmentTree() {}
        SegmentTree(int N, vector<int>& data1) {
            n = N;
            identity = 1;
            st.resize(4*N+10);
            data.resize(N);
            data = data1;

            build(1, 0, n-1);
            // cout << "SEGFAULT\n";
        }

        void pointupdate(int i, int v) {
            point_update(1, 0, n-1, i, v);
            // cout << "SEGFAULT1\n";
        }

        int rangequery(int i, int j) {
            return range_query(1, 0, n-1, i, j);
            // cout << "SEGFAULT2\n";
        }
};

int sign(int a) {
    if (a > 0) return 1;
    else if (a < 0) return -1;
    return 0;
}

char stringysign(int a) {
    if (a == -1) return '-';
    else if (a == 1) return '+';
    return '0';
}

char q;
int A, B;

int main() {
    while (cin >> N >> K) {
        signs.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> signs[i];
            signs[i] = sign(signs[i]);
        }
        
        SegmentTree st = SegmentTree(N, signs);
        string res = "";

        while (K--) {
            cin >> q >> A >> B;
            if (q == 'C') {
                A--;
                st.pointupdate(A, sign(B));
            } else if (q == 'P') {
                A--;
                B--;
                res += stringysign(st.rangequery(A, B));
            }
        }

        cout << res << "\n";
    }
}