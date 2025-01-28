#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

string pattern;
string text;

int main() {
    int a, b;
    cin >> a >> b;
    cin >> pattern >> text;
    if (pattern.find('*') == string::npos) {
        if (pattern == text) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    // split pattern on *
    int pos = pattern.find('*');
    string first = pattern.substr(0, pos);
    string second = pattern.substr(pos + 1);
    // check if first is a prefix of text
    if (text.substr(0, first.size()) != first) {
        cout << "NO" << endl;
        return 0;
    }
    // check if second is a suffix of text
    if (text.substr(text.size() - second.size()) != second) {
        cout << "NO" << endl;
        return 0;
    }
    // check if length of first + length of second <= length of text
    if (first.size() + second.size() > text.size()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}