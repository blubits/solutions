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
    map<string, string> stone_names = {
        {"purple", "Power"},
        {"green", "Time"},
        {"blue", "Space"},
        {"orange", "Soul"},
        {"red", "Reality"},
        {"yellow", "Mind"}
    };
    map<string, bool> stones_present;
    for (auto &[color, gem]: stone_names) stones_present[color] = false;
    int n;
    cin >> n;
    while (n--) {
        string color;
        cin >> color;
        stones_present[color] = true;
    }
    int ans = 0;
    for (auto &[color, is_present]: stones_present)
        if (!is_present) ans++;
    cout << ans << endl;
    for (auto &[color, is_present]: stones_present)
        if (!is_present) cout << stone_names[color] << endl;
    return 0;
}