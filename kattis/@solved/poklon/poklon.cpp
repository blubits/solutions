#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Interval;

bool sorter(Interval &a, Interval &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

bool equals(Interval &a, Interval &b) {
    return a.first == b.first && a.second == b.second;
}

bool contains(Interval &a, Interval &b) {
    if (b.first == 1000001 && b.second == 1000001) return true;
    return a.second <= b.second;
}

int longest_nested_subsequence(vector<Interval> &list) {
    Interval ninf(0, 1000001), inf(1000001, 1000001);
    vector<Interval> ins(list.size() + 1);
    vector<int> lns(list.size());

    // initialize "insertion" array
    ins[0] = ninf;
    ins[1] = list[0];
    for (int i = 2; i <= list.size(); i++) ins[i] = inf;

    // initialize LNS length array
    lns[0] = 1;

    int len = 1, max_i = 0;
    for (int i = 1; i < list.size(); i++) {
        // find correct position in ins array via binary search
        int lo = 0, hi = len, mid = (lo + hi) / 2;
        while (lo <= hi) {
            // find correct place to put the current interval
            mid = (lo + hi) / 2;
            if (contains(list[i], ins[mid])) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ins[lo] = list[i];
        lns[i] = lo;
        if (len < lo) {
            len = lo;
            max_i = i;
        }
        // for (int i = 0; i < ins.size(); i++) {
        //     if (ins[i] == ninf)
        //         cout << "-inf";
        //     else if (ins[i] == inf)
        //         cout << "inf";
        //     else
        //         cout << ins[i].first << "," << ins[i].second;
        //     cout << " ";
        // }
        // cout << endl;
        // cout << "LNS here: " << lo << endl;
    }

    vector<Interval> ans;
    int l = len;
    ans.push_back(list[max_i]);
    for (int i = max_i - 1; i >= 0; i--) {
        if (lns[i] + 1 == l) {
            l--;
            ans.push_back(list[i]);
        }
    }

    cout << len << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return len;
}

int main() {
    vector<Interval> list;
    int a;
    cin >> a;
    while (a--) {
        int f, l;
        cin >> f >> l;
        list.push_back({f, l});
    }
    sort(list.begin(), list.end(), sorter);
    auto it = unique(list.begin(), list.end());
    list.resize(distance(list.begin(), it));
    longest_nested_subsequence(list);
    return 0;
}
