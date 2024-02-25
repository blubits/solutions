#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        vector<int> idx;
        vector<string> numbers;
        // blank line
        getline(cin, s);
        // indexes
        getline(cin, s);
        stringstream ss1(s);
        int i;
        while (ss1 >> i) {
            idx.push_back(i);
        }
        int posn[idx.size()];
        for (int i = 0; i < idx.size(); i++) {
            posn[idx[i] - 1] = i;
        }
        // numbers;
        getline(cin, s);
        stringstream ss2(s);
        string n;
        while (ss2 >> n) {
            numbers.push_back(n);
        }
        for (int i = 0; i < idx.size(); i++) {
            cout << numbers[posn[i]] << endl;
        }
        if (t > 0) cout << endl;
    }
    return 0;
}
