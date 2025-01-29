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
    int n;
    cin >> n;
    vi a(n);
    vector<bool> reduced(n);
    int negatives = 0;
    int smallest_negative = -1;
    int to_delete = -1;
    int ops = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            negatives++;
            if (smallest_negative == -1) smallest_negative = i;
            if (a[i] > a[smallest_negative]) {
                smallest_negative = i;
            }
        } else if (a[i] == 0) {
            reduced[i] = true;
        }
    }
    // Reduce all the zeroes first.
    int last_zero = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (last_zero != -1) {
                cout << 1 << " " << last_zero + 1 << " " << i + 1 << endl;  
                ops++;
            } 
            last_zero = i;
        }
    }
    to_delete = last_zero;
    if (negatives % 2 == 1) {
        // Remove one negative
        reduced[smallest_negative] = true;
        to_delete = smallest_negative;
        if (last_zero != -1) {
            cout << 1 << " " << last_zero + 1 << " " << smallest_negative + 1 << endl;
            ops++;
        }
    }
    if (ops != n - 1 && to_delete != -1) {
        cout << 2 << " " << to_delete + 1 << endl;
        reduced[to_delete] = true;
        ops++;
    }
    int last_idx = -1;
    for (int i = 0; i < n; i++) {
        if (!reduced[i]) {
            if (last_idx != -1) {
                cout << 1 << " " << last_idx + 1 << " " << i + 1 << endl;
                ops++;
            }
            last_idx = i;
            reduced[i] = true;
        }
    }
    return 0;
}