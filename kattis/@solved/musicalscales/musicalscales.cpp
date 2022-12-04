#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    // note => scales where that note is present
    map<string, vector<string>> scales;
    vector<string> notes = {"A",  "A#", "B", "C",  "C#", "D",
                            "D#", "E",  "F", "F#", "G",  "G#"};
    int sz = notes.size();
    for (int i = 0; i < notes.size(); i++) {
        scales[notes[i % sz]].push_back(notes[i]);
        scales[notes[(i + 2) % sz]].push_back(notes[i]);
        scales[notes[(i + 4) % sz]].push_back(notes[i]);
        scales[notes[(i + 5) % sz]].push_back(notes[i]);
        scales[notes[(i + 7) % sz]].push_back(notes[i]);
        scales[notes[(i + 9) % sz]].push_back(notes[i]);
        scales[notes[(i + 11) % sz]].push_back(notes[i]);
    }
    for (auto v : scales) {
        sort(v.second.begin(), v.second.end());
    }

    int k;
    cin >> k;
    string note;
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        cin >> note;
        if (i == 0)
            ans = scales[note];
        else {
            vector<string> newans;
            set_intersection(make_move_iterator(ans.begin()),
                             make_move_iterator(ans.end()),
                             scales[note].begin(), scales[note].end(),
                             inserter(newans, newans.begin()));
            ans.swap(newans);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    if (ans.size() == 0) cout << "none";
    cout << endl;
    return 0;
}
