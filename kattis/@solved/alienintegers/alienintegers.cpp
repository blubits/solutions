#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

set<char> digits;
set<char> digits_excluded;

int main() {
    string n;
    cin >> n;
    
    char ld = n[0];
    int len = n.size();

    for (auto c: n) digits.insert(c);
    for (char c = '0'; c <= '9'; c++) if (!digits.count(c)) digits_excluded.insert(c);

    if (digits_excluded.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (digits_excluded.size() == 1 && digits_excluded.count('0') == 1) {
        cout << "0" << endl;
        return 0;
    }
    
    string smaller = "none";
    string bigger = "none";

    auto closest_ld_above = digits_excluded.lower_bound(ld);
    if (closest_ld_above != digits_excluded.end()) {
        bigger = *closest_ld_above;
        for (int i = 0; i < len - 1; i++) bigger += *digits_excluded.begin();
    } else {
        bigger = *digits_excluded.begin();
        if (bigger == "0") bigger = *digits_excluded.upper_bound('0');
        for (int i = 0; i < len; i++) bigger += *digits_excluded.begin();
    }

    auto closest_ld_below = (closest_ld_above == digits_excluded.begin()) ? digits_excluded.end() : (--digits_excluded.lower_bound(ld));
    if (closest_ld_below != digits_excluded.end()) {
        smaller = *closest_ld_below;
        for (int i = 0; i < len - 1; i++) smaller += *(--digits_excluded.end());
    } else {
        smaller = "";
        for (int i = 0; i < len - 1; i++) smaller += *(--digits_excluded.end());
    }
    
    ll num = stoll(n), big = stoll(bigger), small = stoll(smaller);
    if (abs(num - big) < abs(num - small)) {
        cout << big << endl;
    } else if (abs(num - big) > abs(num - small)) {
        cout << small << endl;
    } else {
        cout << small << " " << big << endl;
    }
    return 0;
}