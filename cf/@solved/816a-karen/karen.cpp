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

bool is_palindrome(string s) {
    return s[0] == s[s.length() - 1] && s[1] == s[s.length() - 2];
}

int main() {
    string s;
    cin >> s;
    int i = 0;
    while (true) {
        if (is_palindrome(s)) {
            cout << i << endl;
            return 0;
        }
        // increment s = "HH:MM"
        if (s[4] == '9') {
            if (s[3] == '5') {
                if (s[1] == '9') {
                    s[0]++;
                    s[1] = '0';
                    s[3] = '0';
                    s[4] = '0';
                } else {
                    s[1]++;
                    s[3] = '0';
                    s[4] = '0';
                    if (s.substr(0, 2) == "24") {
                        s[0] = '0';
                        s[1] = '0';
                    }
                }
            } else {
                s[3]++;
                s[4] = '0';
            }
        } else {
            s[4]++;
        }
        i++;
    }
    return 0;
}