#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

double dist(ii a, ii b) {
    return hypot(a.first - b.first, a.second - b.second);
}

int count_points(set<ii> &lookup, ii pair) {
    int x[] = {-2018, -1680, -1680, -1118, -1118, 0,
               0,     1118,  1118,  1680,  1680,  2018};
    int y[] = {0,    -1118, 1118, -1680, 1680, -2018,
               2018, -1680, 1680, -1118, 1118, 0};
    int ans = 0;
    for (int i = 0; i < 12; i++) {
        int dx = x[i], dy = y[i];
        if (lookup.find({pair.first + dx, pair.second + dy}) != lookup.end()) {
            ans++;
        }
    }
    return ans;
}

int main() {
    vector<ii> pairs;
    set<ii> lookup;
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        pairs.push_back({x, y});
        lookup.insert({x, y});
    }
    sort(pairs.begin(), pairs.end());
    int ans = 0;
    for (int i = 0; i < pairs.size(); i++) {
        ans += count_points(lookup, pairs[i]);
    }
    cout << ans / 2 << endl;
}
