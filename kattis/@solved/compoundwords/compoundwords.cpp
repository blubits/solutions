#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<string> words;
    set<string> compounds;
    string word;
    while (cin >> word) words.push_back(word);
    sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            compounds.insert(words[i] + words[j]);
            compounds.insert(words[j] + words[i]);
        }
    }
    for (auto word : compounds) cout << word << endl;
    return 0;
}
