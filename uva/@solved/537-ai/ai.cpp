#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    cin.ignore();
    for (int c = 1; c <= k; c++) {
        string line, token;
        getline(cin, line);
        stringstream ss(line);
        double u = -1, i = -1, p = -1;
        while (ss >> token) {
            if (token.length() >= 4 && token[1] == '=') {
                // parse
                stringstream st(token);
                char qty, eq;
                double val;
                double mult = 1;
                char prefix;
                st >> qty >> eq >> val >> prefix;
                if (prefix == 'm') mult = 1e-3;
                if (prefix == 'k') mult = 1e3;
                if (prefix == 'M') mult = 1e6;
                if (qty == 'P') p = val * mult;
                if (qty == 'U') u = val * mult;
                if (qty == 'I') i = val * mult;
            }
        }
        printf("Problem #%d\n", c);
        if (u == -1) printf("U=%.2lfV", p / i);
        if (i == -1) printf("I=%.2lfA", p / u);
        if (p == -1) printf("P=%.2lfW", u * i);
        printf("\n\n");
    }
}
