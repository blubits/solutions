#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string n;
        while (ss >> n) {
            tokens.push_back(n);
        }
        string name;
        double total = 0;
        int occ = 0;
        for (auto token : tokens) {
            if (isalpha(token[0])) {
                if (!name.empty()) name += " ";
                name += token;
            } else {
                total += stod(token);
                occ++;
            }
        }
        total /= occ;
        printf("%.6lf ", total);
        cout << name << endl;
    }
}
