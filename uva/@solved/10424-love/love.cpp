#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int digital_sum(int x) {
    int s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        int as = 0, bs = 0;
        for (char c : a) {
            c = tolower(c);
            if ('a' <= c && c <= 'z') {
                as += int(c) - int('a') + 1;
            }
        }
        for (char c : b) {
            c = tolower(c);
            if ('a' <= c && c <= 'z') {
                bs += int(c) - int('a') + 1;
            }
        }
        while (as >= 10) as = digital_sum(as);
        while (bs >= 10) bs = digital_sum(bs);
        double ratio =
            100.0 * min(double(as) / double(bs), double(bs) / double(as));
        cout << setprecision(2) << fixed << ratio << " %" << endl;
    }
}
