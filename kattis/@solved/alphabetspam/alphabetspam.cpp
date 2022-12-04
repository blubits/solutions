#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ws = 0, lc = 0, uc = 0, sy = 0;
    double n = s.size();
    for (char c : s) {
        if (c == '_')
            ws++;
        else if ('a' <= c && c <= 'z')
            lc++;
        else if ('A' <= c && c <= 'Z')
            uc++;
        else
            sy++;
    }
    printf("%.15lf\n%.15lf\n%.15lf\n%.15lf\n", ws / n, lc / n, uc / n, sy / n);
}
