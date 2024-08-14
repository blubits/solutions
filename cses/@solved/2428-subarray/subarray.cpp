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

map<int, int> num_count;

void remove(int x) {
    if (num_count.count(x)) {
        num_count[x] -= 1;
        if (num_count[x] == 0) num_count.erase(x);
    }
}

void insert(int x) {
    if (num_count.count(x)) num_count[x] += 1;
    else num_count[x] = 1;
}

int peek(int x) {
    if (num_count.count(x)) return num_count.size();
    else return num_count.size() + 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int left = -1, right = 0, sz = A.size();
    ll ans = 0;
    while (left < sz && right <= sz) {
        if (left >= 0) {
            remove(A[left]);
        }
        left++;
        while (right < sz && peek(A[right]) <= k) {
            insert(A[right]);
            right++;
        }
        ans += right - left;
    } 
    cout << ans << endl;
    return 0;
}