#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> notes = {"A",  "A#", "B", "C",  "C#", "D",
                         "D#", "E",  "F", "F#", "G",  "G#"};
    map<string, set<string>> scales = {
        {{"A", {"A", "A#", "C", "D", "E", "F", "G"}},
         {"A#", {"A#", "B", "C#", "D#", "F", "F#", "G#"}},
         {"B", {"A", "B", "C", "D", "E", "F#", "G"}},
         {"C", {"A#", "C", "C#", "D#", "F", "G", "G#"}},
         {"C#", {"A", "B", "C#", "D", "E", "F#", "G#"}},
         {"D", {"A", "A#", "C", "D", "D#", "F", "G"}},
         {"D#", {"A#", "B", "C#", "D#", "E", "F#", "G#"}},
         {"E", {"A", "B", "C", "D", "E", "F", "G"}},
         {"F", {"A#", "C", "C#", "D#", "F", "F#", "G#"}},
         {"F#", {"A", "B", "C#", "D", "E", "F#", "G"}},
         {"G", {"A#", "C", "D", "D#", "F", "G", "G#"}},
         {"G#", {"A", "B", "C#", "D#", "E", "F#", "G#"}}}};
    map<string, bool> appears;
    for (auto note : notes) appears[note] = true;
    int t;
    set<string> song_notes;
    cin >> t;
    while (t--) {
        string note;
        cin >> note;
        song_notes.insert(note);
    }
    for (auto song_note : song_notes) {
        for (auto note : notes) {
            if (scales[song_note].find(note) != scales[song_note].end()) {
                appears[note] = appears[note] && true;
            } else {
                appears[note] = appears[note] && false;
            }
        }
    }
    bool present = true;
    for (auto p : appears) {
        if (p.second) {
            present = false;
            cout << p.first << " ";
        }
    }
    if (present) cout << "none";
    cout << endl;
    return 0;
}
