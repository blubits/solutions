#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        map<int, vector<string>> urls;
        string url;
        int rank;
        for (int i = 0; i < 10; i++) {
            cin >> url >> rank;
            if (urls.find(rank) == urls.end()) {
                urls[rank] = vector<string>();
            }
            urls[rank].push_back(url);
        }
        int m = 0;
        for (auto u : urls) {
            m = max(m, u.first);
        }
        cout << "Case #" << c << ":" << endl;
        for (auto s : urls[m]) {
            cout << s << endl;
        }
    }
    return 0;
}
