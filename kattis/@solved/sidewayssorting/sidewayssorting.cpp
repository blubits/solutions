#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare_ignore_case(string l, string r) {
    for (int i = 0; i < l.size(); i++) {
        if (tolower(l[i]) == tolower(r[i])) continue;
        return tolower(l[i]) < tolower(r[i]);
    }
    return false;
}

int main() {
    int r, c, k = 0;
    while (cin >> r >> c && !(r == 0 && c == 0)) {
        vector<string> cols(c);
        for (int i = 0; i < r; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < c; j++) {
                cols[j].push_back(s[j]);
            }
        }
        stable_sort(cols.begin(), cols.end(), compare_ignore_case);
        if (k++) cout << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << cols[j][i];
            }
            cout << endl;
        }
    }
}
