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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        int max = *max_element(nums.begin(), nums.end());
        for (int i = max; i >= 1; i--) {
            int k_greater_than = nums.end() - lower_bound(nums.begin(), nums.end(), i);
            if (i <= k_greater_than) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}