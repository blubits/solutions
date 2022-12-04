#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int k, m;
    while (1) {
        cin >> k;
        if (k == 0) break;
        cin >> m;
        vector<string> courses;
        while (k--) {
            string c;
            cin >> c;
            courses.push_back(c);
        }
        bool graduating = true;
        for (int i = 0; i < m; i++) {
            int c, required, taken = 0;
            cin >> c >> required;
            while (c--) {
                string s;
                cin >> s;
                if (!graduating) continue;
                if (find(courses.begin(), courses.end(), s) != courses.end())
                    taken++;
            }
            if (taken < required) {
                graduating = false;
            }
        }
        if (graduating)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
