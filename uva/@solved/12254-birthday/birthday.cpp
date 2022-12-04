#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> hbd = {
        "Happy", "birthday", "to", "you",   "Happy", "birthday", "to", "you",
        "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    vector<string> names;
    int t;
    string name;
    cin >> t;
    while (t--) {
        cin >> name;
        names.push_back(name);
    }
    for (int i = 0; i < ceil(names.size() / 16.0) * 16; i++) {
        cout << names[i % names.size()] << ": " << hbd[i % 16] << endl;
    }
    return 0;
}
