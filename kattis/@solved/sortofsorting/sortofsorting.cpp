#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare_first_two(string l, string r) {
    for (int i = 0; i < 2; i++) {
        if (l[i] == r[i]) continue;
        return l[i] < r[i];
    }
    return false;
}

int main() {
    int t, c = 0;
    while (cin >> t && t != 0) {
        vector<string> names(t);
        for (int i = 0; i < t; i++) {
            cin >> names[i];
        }
        stable_sort(names.begin(), names.end(), compare_first_two);
        if (c++) cout << endl;
        for (auto s : names) cout << s << endl;
    }
}
