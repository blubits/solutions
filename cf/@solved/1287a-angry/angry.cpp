#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int k;
        string s;
        cin >> k >> s;
        int curr_p = 0;
        int longest_p = 0;
        bool a_seen = false;
        for (auto &c : s) {
            switch (c) {
                case 'P':
                    curr_p++;
                    break;
                case 'A':
                    if (a_seen) longest_p = max(curr_p, longest_p);
                    curr_p = 0;
                    a_seen = true;
                    break;
                default:
                    break;
            }
        }
        if (a_seen) longest_p = max(curr_p, longest_p);
        cout << longest_p << endl;
    }
    return 0;
}