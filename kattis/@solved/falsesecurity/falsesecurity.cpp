#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main() {
    map<char, string> morse = {
        {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."},    {'F', "..-."}, {'G', "--."},  {'H', "...."},
        {'I', ".."},   {'J', ".---"}, {'K', "-.-"},  {'L', ".-.."},
        {'M', "--"},   {'N', "-."},   {'O', "---"},  {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
        {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'_', "..--"}, {',', ".-.-"},
        {'.', "---."}, {'?', "----"}};

    map<string, char> alph;
    for (auto p : morse) alph[p.second] = p.first;

    string line;
    while (getline(cin, line)) {
        string enc;
        stack<int> lengths;
        for (char c : line) {
            enc += morse[c];
            lengths.push(morse[c].size());
        }
        string dec;
        int s = 0;
        while (!lengths.empty()) {
            int l = lengths.top();
            lengths.pop();
            string sub = enc.substr(s, l);
            dec += alph[sub];
            s += l;
        }
        cout << dec << endl;
    }
    return 0;
}
