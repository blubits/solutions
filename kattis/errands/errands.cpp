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

map<string, int> poi_idx;
vector<string> poi_name;
vector<pair<double, double>> poi_posn;

double dp[(1 << 12)][12];
int pre[(1 << 12)][12];
vector<pair<double, double>> curr_posns;
vector<string> curr_names;

double dist(pair<double, double> a, pair<double, double> b) {
    return hypot(b.first - a.first, b.second - a.second);
}

// initial state (answer): full bitmask, n - 1
// base case: almost empty bitmask
// i have the answer for <full>, what was the last (or second to the last) decision I made?
double tsp(int bitmask, int lp) {
    if (bitmask == 1) return 0;
    if (dp[bitmask][lp] != -1.0) return dp[bitmask][lp];
    double ans = 1e9;
    for (int m = bitmask; m; m -= LSOne(m)) {
        int slp = __builtin_ctz(m);
        if (slp != lp) {
            int bitmask_without_lp = bitmask - (1 << lp);
            double curr_ans = tsp(bitmask_without_lp, slp) +
                              dist(curr_posns[slp], curr_posns[lp]);
            if (ans > curr_ans) {
                ans = curr_ans;
                pre[bitmask][lp] = slp;
            }
        }
    }
    dp[bitmask][lp] = ans;
    return ans;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string poi;
        double x, y;
        cin >> poi >> x >> y;
        poi_idx[poi] = i;
        poi_name.push_back(poi);
        poi_posn.push_back({x, y});
    }
    cin.ignore();
    string line;
    while (getline(cin, line)) {
        curr_posns.clear();
        curr_names.clear();
        curr_posns.push_back(poi_posn[poi_idx["home"]]);
        curr_names.push_back("home");
        istringstream ss_poi(line);
        string poi;
        while (ss_poi >> poi) {
            curr_posns.push_back(poi_posn[poi_idx[poi]]);
            curr_names.push_back(poi);
        }
        curr_names.push_back("work");
        curr_posns.push_back(poi_posn[poi_idx["work"]]);
        int ct = curr_names.size();
        fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -1.0);
        tsp((1 << ct) - 1, ct - 1);
        int cb = (1 << ct) - 1, cct = ct - 1;
        while (cb != 1) {
            if (cct != ct - 1) cout << curr_names[cct] << " ";
            tie(cb, cct) = make_pair(cb - (1 << cct), pre[cb][cct]);
        }
        cout << endl;
    }
    return 0;
}