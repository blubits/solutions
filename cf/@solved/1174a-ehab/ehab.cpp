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
    vi nums(2 * n);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> nums[i];
        if (0 <= i && i < n) sum1 += nums[i];
        else sum2 += nums[i];
    }
    if (sum1 != sum2) {
        for (int i = 0; i < 2 * n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    } else {
        bool has_unequal = false;
        for (int i = 0; i < n; i++) {
            for (int j = n; j < 2 * n; j++) {
                if (nums[i] != nums[j]) {
                    has_unequal = true;
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            if (has_unequal) break;
        }
        if (has_unequal) {
            for (int i = 0; i < 2 * n; i++) {
                cout << nums[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}