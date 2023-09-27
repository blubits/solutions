#include <bits/stdc++.h>

using namespace std;

int abs(int i) {
    if (i >= 0) return i;
    return -i;
}

class SegTree {
    private:
        vector<int> st;
        vector<int> data;
        int identity = 1;
        int N;

        int left(int i) {
            return 2*i;
        }

        int right(int i) {
            return 2*i+1;
        }

        int combine(int a, int b) {
            return gcd(a, b);
        }

        void build(int i, int l, int r) {
            if (l > r)
                return;
            if (l == r) {
                st[i] = data[l];
                return;
            }

            int m = (l+r)/2;
            build(left(i), l, m);
            build(right(i), m+1, r);
            st[i] = combine(st[left(i)], st[right(i)]);
        }

        int range_rec_query(int idx, int l, int r, int i, int j) {
            if (i > j) return 0;
            if (l == i && r == j) {
                return st[idx];
            }
            int m = (l+r)/2;
            return combine(range_rec_query(left(idx), l, m, i, min(j, m)),
                        range_rec_query(right(idx), m+1, r, max(i, m+1), j));
        }
    public:
        SegTree(vector<int>& d) {
            N = d.size();
            data.resize(N);
            data = d;
            st.resize(4*N+10, identity);
            build(1, 0, N-1);
        }

        int range_query(int i, int j) {
            return range_rec_query(1, 0, N-1, i, j);
        }
};

class SegTree1 {
    private:
        vector<int> st;
        vector<int> data;
        int identity = 1e8;
        int N;

        int left(int i) {
            return 2*i;
        }

        int right(int i) {
            return 2*i+1;
        }

        int combine(int a, int b) {
            return min(a, b);
        }

        void build(int i, int l, int r) {
            if (l > r)
                return;
            if (l == r) {
                st[i] = data[l];
                return;
            }

            int m = (l+r)/2;
            build(left(i), l, m);
            build(right(i), m+1, r);
            st[i] = combine(st[left(i)], st[right(i)]);
        }

        int range_rec_query(int idx, int l, int r, int i, int j) {
            if (i > j) return identity;
            if (l == i && r == j) {
                return st[idx];
            }
            int m = (l+r)/2;
            return combine(range_rec_query(left(idx), l, m, i, min(j, m)),
                        range_rec_query(right(idx), m+1, r, max(i, m+1), j));
        }
    public:
        SegTree1(vector<int> d) {
            N = d.size();
            data.resize(N);
            data = d;
            st.resize(4*N+10, identity);
            build(1, 0, N-1);
        }

        int range_query(int i, int j) {
            return range_rec_query(1, 0, N-1, i, j);
        }

        void printS() {
            for (auto l: st) {
                cout << l << " ";
            }
            cout << '\n';
        }
};

int n;
vector<int> s;
vector<pair<int, int> > s1;
int t;
int l, r;

int main() {
    scanf("%d", &n);
    s.resize(n);
    s1.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        s1[i] = pair<int, int>(s[i], i);
    }

    sort(s1.begin(), s1.end());

    SegTree st = SegTree(s);
    SegTree1 minst = SegTree1(s);
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &l, &r);
        l--; r--;
        int gc = st.range_query(l, r);
        if (gc == 0) {
            printf("0\n");
        } else if (gc != minst.range_query(l, r)) {
            printf("%d\n", r-l+1);
        } else {
            pair<int, int> p1 = make_pair(gc, l);
            pair<int, int> p2 = make_pair(gc, r);
            auto loweri = lower_bound(s1.begin(), s1.end(), p1);
            int lower = distance(s1.begin(), loweri);
            auto upperi = upper_bound(s1.begin(), s1.end(), p2);
            int upper = distance(s1.begin(), upperi)-1;

            printf("%d\n", r-l+1 - (upper - lower + 1));
        }
    }
}