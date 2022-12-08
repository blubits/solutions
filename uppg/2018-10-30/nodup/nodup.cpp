#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<string> sv;
    bool dupe = false;
    while (cin >> s) {
        if (find(sv.begin(), sv.end(), s) != sv.end()) {
            dupe = true;
            break;
        } else {
            sv.push_back(s);
        }
    }
    if (dupe)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
}
