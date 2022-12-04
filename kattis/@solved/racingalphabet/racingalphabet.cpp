#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int pos(char c) {
    if (c == '\'')
        return 27;
    else if (c == ' ')
        return 26;
    else
        return c - 'A';
}

int main() {
    const double PI = atan(1.0) * 4;
    const double C = PI * 60.0;  // circumference in feet
    const double STEP = C / 28;
    int k;
    cin >> k;
    cin.ignore();
    while (k--) {
        string s;
        getline(cin, s);
        double t = 1;
        for (int i = 1; i < s.size(); i++) {
            int to = max(pos(s[i]), pos(s[i - 1]));
            int from = min(pos(s[i]), pos(s[i - 1]));
            double dist = min(to - from, (28 - to) + from);
            double d = STEP * dist;
            t += 1 + (d / 15);
        }
        printf("%.10lf\n", t);
    }
}
