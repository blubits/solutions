#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<pair<double, double>> intervals;

int main() {
    int n, cs = 0;
    double d;
    while (cin >> n >> d && !(n == 0 && d == 0)) {
        intervals.clear();
        double x, y;
        bool no_ans = false;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (y > d) no_ans = true;
            else {
                double xleft = x - sqrt(d*d - y*y), xright = x + sqrt(d*d - y*y);
                intervals.push_back({xleft, xright});
            }
        }
        sort(intervals.begin(), intervals.end());
        for (auto &[l, r]: intervals) cout << l << " " << r << endl;
        double coverage = -1e9;
        int count = 0, curr_interval = 0;
        while (curr_interval < n) {
            while (curr_interval < n && intervals[curr_interval].first <= coverage) {
                if (coverage >= intervals[curr_interval].second)
                     coverage = intervals[curr_interval].second;
                curr_interval++;
                cout << count << " " << coverage << endl;
            }
            count++;
            coverage = intervals[curr_interval].second;
            cout << count << " " << curr_interval << " " << coverage << endl;
        }
        printf("Case %d: %d\n", ++cs, no_ans ? -1 : count - 1);
    }
    return 0;
}