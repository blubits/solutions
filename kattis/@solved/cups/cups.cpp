#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_num(string s) {
    for (auto c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, string>> cups;
    while (t--) {
        string l, r;
        cin >> l >> r;
        if (is_num(l)) {
            cups.push_back(make_pair(stoi(l) / 2, r));
        } else {
            cups.push_back(make_pair(stoi(r), l));
        }
    }
    sort(cups.begin(), cups.end());
    for (auto p : cups) {
        cout << p.second << endl;
    }
    return 0;
}
