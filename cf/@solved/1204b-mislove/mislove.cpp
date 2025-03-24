#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    int smallest_sum = 0, largest_sum = 0;
    int pow2 = 1, i = 1;
    while (i <= r) {
        if (i <= l) smallest_sum += pow2;
        largest_sum += pow2;
        pow2 *= 2;
        i++;
    }
    smallest_sum += (n - l);
    largest_sum += (n - r) * (pow2 / 2);
    cout << smallest_sum << " " << largest_sum << endl;
    return 0;
}