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
        int n;
        string s;
        cin >> n >> s;
        int num_d = 0, num_k = 0;
        unordered_map<int, unordered_map<int, int>> ratios;
        vector<int> ratio_counts;
        for (auto c : s) {
            if (c == 'D') num_d++;
            else num_k++;
            int g = gcd(num_d, num_k);
            int d_ratio = num_d / g;
            int k_ratio = num_k / g;
            ratios[d_ratio][k_ratio]++;
            ratio_counts.push_back(ratios[d_ratio][k_ratio]);
        }
        for (auto r : ratio_counts) {
            cout << r << " ";
        }
        cout << endl;
    }
    return 0;
}