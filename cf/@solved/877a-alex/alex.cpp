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

// Find the number of times string t occurs in string s.
int count(string s, string t) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[0]) {
            if (s.substr(i, t.size()) == t) count++;
        }
    }
    return count;
}

int main() {
    string friends[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    string problem_name;
    cin >> problem_name;
    int num_friends = 0;
    for (int i = 0; i < 5; i++) {
        num_friends += count(problem_name, friends[i]);
    }
    if (num_friends == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}