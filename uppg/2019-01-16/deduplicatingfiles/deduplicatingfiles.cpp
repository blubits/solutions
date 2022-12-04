#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int hashfunc(string line) {
    int ans = 0;
    for (auto c : line) {
        // cout << c << " " << int(c) << endl;
        ans ^= int(c);
    }
    // cout << line << " " << ans << endl;
    return ans;
}

int main() {
    int t;

    while (cin >> t && t != 0) {
        set<string> files;
        vector<pair<int, string>> hashes;
        cin.ignore();
        for (int i = 0; i < t; i++) {
            string line;
            getline(cin, line);
            files.insert(line);
            hashes.push_back({hashfunc(line), line});
        }
        // for (auto f : files) {
        //     hashes.push_back(hashfunc(f));
        // }
        sort(hashes.begin(), hashes.end());
        // for (auto c : hashes) cout << c << " ";
        // cout << endl;
        int uniq = files.size(), coll = 0;
        for (int i = 0; i < hashes.size(); i++) {
            for (int j = i + 1; j < hashes.size(); j++) {
                if (hashes[i].first == hashes[j].first &&
                    hashes[i].second != hashes[j].second)
                    coll++;
            }
        }
        cout << uniq << " " << coll << endl;
    }

    return 0;
}
