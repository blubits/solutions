#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vii pairs;
vii solution;

bool intcov_comparator(ii &a, ii &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        pairs.clear();
        solution.clear();
        int M;
        cin >> M;
        int i, j;
        while (cin >> i >> j && !(i == 0 && j == 0)) {
            pairs.push_back({i, j});
        }
        sort(pairs.begin(), pairs.end(), intcov_comparator);
        int end = 0, curridx = 0;
        bool first = true;
        ii curr = {-1, -1};
        // for each interval [a, b]...
        while (curridx < pairs.size()) {
            auto &[a, b] = pairs[curridx];
            if (a <= end) {
                // if left endpoint <= current coverage,
                // this is a candidate for a good interval
                // select it either if
                //  - it is the first interval found, or
                //  - if the right coverage improves upon the first
                //    interval found
                if (first) {
                    curr = {a, b};
                    first = false;
                } else if (b > curr.second) {
                    curr = {a, b};
                }
                curridx++;
            } else { 
                // if curr left endpoint breaks at current coverage,
                // see if our greedy search above is fruitful
                // if it isn't (first == true) then gap found
                // and we can't cover the entire thing
                if (first) break;
                // otherwise, add our greedily selected interval
                // and update the coverage based on this interval
                solution.push_back(curr);
                end = curr.second;
                first = true;
                if (end >= M) break;
            }
        }
        if (!first) solution.push_back(curr);
        if (solution[solution.size() - 1].second < M) cout << 0 << endl;
        else {
            cout << solution.size() << endl;
            for (auto &[a, b]: solution) {
                cout << a << " " << b << endl;
            }
        }
        cout << endl;
    }
    return 0;
}