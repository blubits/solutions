#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int N;
    cin >> N;

    unordered_map<string, set<string>> words;
    unordered_map<string, int> freq;
    while (N--) {
        string name;
        cin >> name;
        if (words.find(name) == words.end()) {
            words[name] = set<string>();
        }
        while (cin.peek() != '\n') {
            string word;
            cin >> word;
            words[name].emplace(word);
            if (freq.find(word) == freq.end()) {
                freq[word] = 1;
            } else {
                freq[word] += 1;
            }
        }
    }

    unordered_map<string, int> freq_users;
    for (auto &[n, w]: words) {
        for (auto &wd: w) {
            if (freq_users.find(wd) == freq_users.end()) {
                freq_users[wd] = 1;
            } else {
                freq_users[wd] += 1;
            }
        }
    }

    vector<pair<int, string>> freq_pairs;
    for (auto &[w, n]: freq_users) {
        if (n == words.size()) {
            freq_pairs.push_back({-freq[w], w});
        }
    }
    sort(freq_pairs.begin(), freq_pairs.end());
    if (freq_pairs.empty()) cout << "ALL CLEAR" << endl;
    for (auto &[n, w]: freq_pairs) {
        cout << w << endl;
    }

    return 0;
}