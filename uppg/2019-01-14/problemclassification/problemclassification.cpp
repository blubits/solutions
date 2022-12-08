#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main() {
    int t;
    multimap<string, string> word_to_class;
    map<string, int> classes;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line, token, cls;
        int k;
        getline(cin, line);
        stringstream ss(line);
        ss >> cls >> k;
        classes[cls] = 0;
        while (k--) {
            ss >> token;
            word_to_class.insert({token, cls});
        }
    }
    string word;
    while (cin >> word) {
        auto rng = word_to_class.equal_range(word);
        for (auto i = rng.first; i != rng.second; i++) {
            // cout << word << " " << i->second << endl;
            classes[i->second] += 1;
        }
    }
    int max = 0;
    for (auto c : classes) {
        if (c.second > max) max = c.second;
    }
    for (auto c : classes) {
        if (c.second == max) cout << c.first << endl;
    }
    return 0;
}
