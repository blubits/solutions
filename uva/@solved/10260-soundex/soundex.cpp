#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<char, char> dat = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'}, {'C', '2'}, {'G', '2'},
        {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'}, {'L', '4'}, {'M', '5'}, {'N', '5'}, {'R', '6'}};

    string s;
    while (cin >> s) {
        string codex;
        char pc = '9';
        for (auto c : s) {
            if (dat.find(c) != dat.end()) {
                if (dat.find(pc) == dat.end() || dat[pc] != dat[c]) {
                    codex += dat[c];
                }
            }
            pc = c;
        }
        cout << codex << endl;
    }
}
