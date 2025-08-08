#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

vector<string> songs;
unordered_map<string, unordered_set<int>> occurences;

// string -> songs it occurs in

auto comp = [](const string& a, const string& b) {
    return a.size() == b.size() ? a < b : a.size() < b.size();
};

void add(const string& song, int idx) {
    // for every substring of the song
    for (int sz = 1; sz <= song.size(); sz++) {
        for (int i = 0; i <= song.size() - sz; i++) {
            string sub = song.substr(i, sz);
            // if the substring is not in the map, add it
            if (occurences.find(sub) == occurences.end()) {
                occurences[sub] = unordered_set<int>();
            }
            // add the index of the song to the set of occurences for this substring
            occurences[sub].insert(idx);
        }
    }
}

string solve(const string& song) {
    set<string, decltype(comp)> unique_subs(comp);
    // for every substring of the song
    for (int sz = 1; sz <= song.size(); sz++) {
        for (int i = 0; i <= song.size() - sz; i++) {
            string sub = song.substr(i, sz);
            // if the substring is in the map and it occurs only once, return it
            if (occurences[sub].size() == 1) {
                unique_subs.insert(sub);
            }
        }
    }
    return unique_subs.empty() ? ":(" : "\"" + *unique_subs.begin() + "\"";
}

int main() {
    int T;
    cin >> T;
    for (int j = 0; j < T; j++) {
        cout << "Case #" << j + 1 << ":" << endl;
        songs.clear();
        occurences.clear();
        int n;
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string song;
            getline(cin, song);
            transform(song.begin(), song.end(), song.begin(), ::toupper);
            songs.push_back(song);
        }
        if (n == 1) {
            cout << "\"\"" << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            add(songs[i], i);
        }
        for (const auto& song: songs) {
            cout << solve(song) << endl;
        }
    }
    return 0;
}