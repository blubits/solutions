#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sort_by_upper(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> minions(t);
    for (int i = 0; i < t; i++) {
        int ml, mh;
        cin >> ml >> mh;
        minions[i] = {ml, mh};
    }
    sort(minions.begin(), minions.end(), sort_by_upper);
    int r = 1, max_u = minions[0].second;
    for (int i = 1; i < t; i++) {
        if (max_u < minions[i].first) {
            max_u = minions[i].second;
            r++;
        }
    }
    cout << r << endl;
}
