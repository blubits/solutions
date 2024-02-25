#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int price(int cons) {
    int p = 0;
    p += min(max(0, cons * 2), 2*100); cons -= 100;
    p += min(max(0, cons * 3), 3*9900); cons -= 9900;
    p += min(max(0, cons * 5), 5*990000); cons -= 990000;
    p += max(0, cons * 7);
    return p;
}

int cons(int price) {
    int c = 0;
    c += min(max(0, price/2), 100); price -= 2*100;
    c += min(max(0, price/3), 9900); price -= 3*9900;
    c += min(max(0, price/5), 990000); price -= 5*990000;
    c += max(0, price/7);
    return c;
}

int main() {
    int a, b; // a: cost of total bill, b: difference of split bills
    while (cin >> a >> b && !(a == 0 && b == 0)) {
        int total_cons = cons(a);
        int lo = 0, hi = total_cons; // C(a) = max possible consumption
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int diff = price(total_cons - mid) - price(mid);
            if (diff > b) {
                lo = mid;
            } else if (diff < b) {
                hi = mid;
            } else {
                cout << price(mid) << endl;
                break;
            }
        }
    }
    return 0;
}