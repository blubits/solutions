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
    int t;
    cin >> t;
    while (t--) {
        vector<int> nums(3);
        for (int i = 0; i < 3; i++) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        if (nums[2] >= nums[0] + nums[1]) {
            cout << nums[0] + nums[1] << endl;
        } else {
            cout << (nums[0] + nums[1] + nums[2]) / 2 << endl;
        }
    }
    return 0;
}