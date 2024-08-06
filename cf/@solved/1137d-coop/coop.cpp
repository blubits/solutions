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

vector<int> group_id(10);

void issue_command(const vector<int> &to_move) {
    // Issue output
    cout << "next";
    for (auto i: to_move) cout << " " << i;
    cout << endl;
    // Read in input
    int len_id;
    cin >> len_id;
    for (int i = 0; i < len_id; i++) {
        string grp;
        cin >> grp;
        for (auto c: grp) group_id[c - '0'] = i;
    }
}

int main() {
    do {
        issue_command({0, 1});
        issue_command({1});
    } while (group_id[0] != group_id[1]); 
    while (group_id[1] != group_id[2]) {
        issue_command({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    }
    cout << "done";
    return 0;
}